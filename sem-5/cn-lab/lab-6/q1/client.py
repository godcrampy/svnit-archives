import socket
import time
import threading
import time
import os

print("Starting Slave Client...")

msg = "."


def comm():
    ClientSocket = socket.socket()
    host = "127.0.0.1"
    port = int(input("Select Port to connect to: "))

    print("Waiting for connection")
    try:
        ClientSocket.connect((host, port))
    except socket.error as e:
        print(str(e))
        exit()
    print("Connected to Master successfully. Enter messages. Press \"exit\" to quit")
    Response = ClientSocket.recv(1024)
    try:
        while True:
            global msg
            time.sleep(1)
            if msg == "exit":
                exit()
            if msg != ".":
                print(f"Sending: {msg}")
            ClientSocket.send(msg.encode())
            res = ClientSocket.recv(1024).decode()
            if res != ".":
                print(f"Master Responded with: {res}")
            msg = "."
    except Exception:
        ClientSocket.close()


def file_writer():
    while True:
        user_input = input()
        global msg
        msg = user_input
        if msg == "exit":
            print("Closing Client...")
            exit()


t1 = threading.Thread(target=comm)
t2 = threading.Thread(target=file_writer)

t1.start()
time.sleep(0.1)
t2.start()

t1.join()
t2.join()
