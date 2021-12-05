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
    key = input("Enter key value: ")
    if len(key) != len(message):
        print("ERROR: Key and message length should be same")
        exit(0)
    result = ""
    hex_val = ""

    print("Message:")
    for i in message:
        print(f"{i}: {bin(ord(i))[2:].zfill(8)}")

    print()
    print("Key:")
    for i in key:
        print(f"{i}: {bin(ord(i))[2:].zfill(8)}")

    print()
    print("XOR: ")
    for i in range(len(message)):
        a = ord(message[i])
        b = ord(key[i])

        print(
            f"{bin(a)[2:]} ^ {bin(b)[2:]} = {bin(a ^ b)[2:].zfill(8)}")

        result += chr(a ^ b)
        hex_val += f"{hex(a ^ b)[2:].zfill(2)} "

    print(f"Final hex:\n{hex_val}")
    print("Saved to hex.txt")

    with open("hex.txt", "w") as f:
        f.write(hex_val)


def perform_decyption():
    filename = input("Enter hex file to be decrypted: ")
    message = file_to_str(filename)
    hex_vals = message.split(" ")[:-1]

    key = input("Enter key value: ")
    if len(key) != len(hex_vals):
        print("ERROR: Key and message length should be same")
        exit(0)

    result = ""

    print("Hex Values:")
    for i in hex_vals:
        print(f"{i}: {bin(int(i, 16))[2:].zfill(8)}")

    print()
    print("Key:")
    for i in key:
        print(f"{i}: {bin(ord(i))[2:].zfill(8)}")

    print()
    print("XOR: ")
    for i in range(len(hex_vals)):
        a = int(hex_vals[i], 16)
        b = ord(key[i])

        print(
            f"{bin(a)[2:].zfill(8)} ^ {bin(b)[2:]} = {bin(a ^ b)[2:].zfill(8)}")

        result += chr(a ^ b)
    print(f"Final string:\n{result}")
    print("Saved to ans.txt")

    with open("ans.txt", "w") as f:
        f.write(result)


is_encrypt = recursive_read(
    ["e", "d"], "Enter 'e' for encryption or 'd' for decryption: ") == "e"


if is_encrypt:
    perform_encryption()
else:
    perform_decyption()
