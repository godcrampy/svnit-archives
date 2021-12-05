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


def file_to_str(filename):
    try:
        with open(filename, 'r') as file:
            return file.read()
    except:
        print("Error: File not found!")
        exit(1)


def perform_encryption():
    filename = input("Enter file to be encrypted: ")
    message = file_to_str(filename)
    key = recursive_read_int("Enter key value: ")
    result = ""

    for i in range(len(message)):
        char = message[i]
        if char.isupper():
            result += chr((ord(char) + key - 65) % 26 + 65)
        elif char.islower():
            result += chr((ord(char) + key - 97) % 26 + 97)
        else:
            result += char

    print(f"Final string:\n{result}")


def perform_decyption():
    filename = input("Enter file to be decrypted: ")
    message = file_to_str(filename)
    key = recursive_read_int("Enter key value: ")
    result = ""

    for i in range(len(message)):
        char = message[i]
        if char.isupper():
            result += chr((ord(char) - key - 65) % 26 + 65)
        elif char.islower():
            result += chr((ord(char) - key - 97) % 26 + 97)
        else:
            result += char

    print(f"Final string:\n{result}")


is_encrypt = recursive_read(
    ["e", "d"], "Enter 'e' for encryption or 'd' for decryption: ") == "e"


if is_encrypt:
    perform_encryption()
else:
    perform_decyption()
