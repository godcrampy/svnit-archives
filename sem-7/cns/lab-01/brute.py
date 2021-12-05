def file_to_str(filename):
    try:
        with open(filename, 'r') as file:
            return file.read()
    except:
        print("Error: File not found!")
        exit(1)


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


def shift(message, key):
    result = ""

    for i in range(len(message)):
        char = message[i]
        if char.isupper():
            result += chr((ord(char) + key - 65) % 26 + 65)
        elif char.islower():
            result += chr((ord(char) + key - 97) % 26 + 97)
        else:
            result += char

    return result


def head(message):
    return "\n".join(message.split("\n")[:4])


filename = input("Enter file to be encrypted: ")
message = file_to_str(filename)

while True:
    key = recursive_read_int("Enter next key to try: ")
    result = shift(message, key)
    print("Text: ")
    print(head(result))
    is_ok = recursive_read(
        ["y", "n"], "Enter 'y' to quit or 'n' for new key: ") == "y"
    if is_ok:
        print("Final Message:")
        print(result)
        break
