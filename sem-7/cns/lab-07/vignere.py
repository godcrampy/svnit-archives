def recursive_read(allowed_input, message=""):
    # Recursively reads user input until input is not in allowd_input
    while True:
        user_input = input(message)
        if user_input in allowed_input:
            return user_input


def recursive_read_int(message=""):
    # Recursively reads user input until input is not in allowd_input
    while True:
        user_input = input(message)
        try:
            value = int(user_input)
            return value
        except:
            pass

m = 26


def multiplicative_inverse(a):
    for i in range(1, m):
        remainder = ((i * m) + 1) % a
        if remainder == 0:
            return ((i * m) + 1) / a

    return 0


def perform_encryption():
    message = input("Enter message: ").upper().replace(" ", "")
    key = input("Enter key: ").upper().replace(" ", "")

    result = ""
    mask = ""

    for i in range(len(message)):
      mask += key[i % len(key)]
      result += chr(((ord(message[i]) - ord('A') + ord(key[(i % len(key))]) - ord('A')) % m) + ord('A'))


    print(f"Mask: {mask}")
    print(f"Final string: {result}")


def perform_decryption():
    message = input("Enter message: ").upper().replace(" ", "")
    key = input("Enter key: ").upper().replace(" ", "")

    result = ""
    mask = ""

    for i in range(len(message)):
      mask += key[i % len(key)]
      result += chr(((ord(message[i]) - ord(key[(i % len(key))])) % m) + ord('A'))


    print(f"Mask: {mask}")
    print(f"Final string: {result}")


is_encrypt = recursive_read(
    ["e", "d"], "Enter 'e' for encryption or 'd' for decryption: ") == "e"


if is_encrypt:
    perform_encryption()
else:
    perform_decryption()
