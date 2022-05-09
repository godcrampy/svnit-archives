from encrypt import Cipher, generate_key
from threading import Thread
from queue import Queue
from time import sleep
from random import randint

def random_wait():
    # random wait between 1 and 3 seconds
    sleep(randint(50, 200) / 100)

ka = generate_key()
kb = generate_key()

a_id = 100
b_id = 200

def kdc(kdc_alice_queue, ka, kb):
    a_cipher = Cipher(ka)
    b_cipher = Cipher(kb)
    print('KDC: Starting KDC server...')
    print('KDC: Waiting for Alice...')
    random_wait()

    # Step 1
    while kdc_alice_queue.empty():
        sleep(1)
    msg = kdc_alice_queue.get()
    print(f'KDC: Received from Alice Server {msg}')
    Na = msg[-1]

    # Step 2
    print()
    print('========== Step 2 KDC -> A (Na, Kab, B, (Kab, A)Kb)Ka ==========')
    input(f'KDC: Executing Step 2: Press enter to continue... ')
    kab = generate_key()
    payload = [Na, kab, b_id, b_cipher.encrypt([kab, a_id])]
    print(f'KDC: Payload {payload}')
    print(f'KDC: Kab: {kab}')
    txt = a_cipher.encrypt(payload)
    print(f'KDC: Encrypted Payload {txt}')
    input('KDC: Press Enter to send payload to Alice... ')
    kdc_alice_queue.put(txt)
    

def alice(kdc_alice_queue, alice_bob_queue, ka):
    a_cipher = Cipher(ka)
    print(f'ALICE: Starting Alice server (id: {a_id})...')
    random_wait()

    # Step 1
    print()
    print('========== Step 1 (A -> KDC (A, B, Na)) ==========')
    input('ALICE: Executing Step 1: Press enter to continue... ')
    Na = randint(1000, 9999)
    print(f'ALICE: Nonce: {Na}')
    kdc_alice_queue.put([a_id, b_id, Na])
    print('ALICE: Done')
    sleep(3)

    # Step 2
    while kdc_alice_queue.empty():
        sleep(1)
    
    msg = kdc_alice_queue.get()
    print()
    print(f'ALICE: Received encrypted message from KDC {msg}')
    input('ALICE: Press enter to decode... ')
    msg = a_cipher.decrypt(msg)
    print(f'ALICE: Decrypted: {msg}')
    print(f'ALICE: Kab: {msg[1]}')
    kab = msg[1]
    ab_cipher = Cipher(kab)

    # Step 3
    print()
    print('========== Step 3 (A -> B (Kab, A)Kb) ==========')
    input('ALICE: Press enter to send encrypted keys to Bob... ')
    alice_bob_queue.put(msg[3])
    sleep(3)

    # Step 4
    while alice_bob_queue.empty():
        sleep(1)
    
    msg = alice_bob_queue.get()
    print()
    print(f'ALICE: Received encrypted message from Bob {msg}')
    input('ALICE: Press enter to decode... ')
    msg = ab_cipher.decrypt(msg)
    print(f'ALICE: Decrypted: {msg}')

    # Step 5
    print()
    print('========== Step 5 (A -> B (Nb - 1)Kab) ==========')
    input(f'ALICE: Press enter to send nonce - 1 to BOB... ')
    msg -= 1
    alice_bob_queue.put(ab_cipher.encrypt(msg))



    
def bob(alice_bob_queue, kb):
    b_cipher = Cipher(kb)

    # Step 3
    while alice_bob_queue.empty():
        sleep(1)
    
    print()
    msg = alice_bob_queue.get()
    print(f'BOB: Received keys from Alice {msg}')
    input(f'BOB: Press enter to decrypt... ')

    msg = b_cipher.decrypt(msg)
    print(f'BOB: Decrypted: {msg}')
    print(f'BOB: Kab: {msg[0]}')
    kab = msg[0]
    ab_cipher = Cipher(kab)

    # Step 4
    print()
    print('========== Step 4 (B -> A (Nb)Kab) ==========')
    Nb = randint(1000, 9999)
    print(f'BOB: Nonce: {Nb}')
    input(f'BOB: Press enter to send encrypted nonce to Alice... ')
    alice_bob_queue.put(ab_cipher.encrypt(Nb))
    sleep(3)

    # Step 5
    while alice_bob_queue.empty():
        sleep(1)
    
    msg = alice_bob_queue.get()
    print()
    print(f'BOB: Received encrypted message from Alice {msg}')
    input(f'BOB: Press enter to decode... ')
    msg = ab_cipher.decrypt(msg)
    print(f'BOB: Decrypted: {msg}')
    print(f'BOB: Nb: {msg}')
    print(f'BOB: Key is Verified')


kdc_alice_queue = Queue()
alice_bob_queue = Queue()

kdc_thread = Thread(target = kdc, args = (kdc_alice_queue, ka, kb))
alice_thread = Thread(target = alice, args = (kdc_alice_queue, alice_bob_queue, ka))
bob_thread = Thread(target = bob, args = (alice_bob_queue, kb))

kdc_thread.start()
alice_thread.start()
bob_thread.start()

kdc_thread.join()
alice_thread.join()
bob_thread.join()
print()
print('ALICE: Shutting down Alice server...')
print('KDC: Shutting down KDC server...')
print('BOB: Shutting down Bob server...')
