import math
from tabulate import tabulate

def recursive_read(allowed_input, message=""):
    # Recursively reads user input until input is not in allowed_input
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

    table = []

    size = len(message)
    row_count = key
    column_count = math.ceil(size / key)
    extra_bits = row_count * column_count - size

    for _ in range(extra_bits):
      message += " "

    k = 0

    for _ in range(row_count):
      table.append([])

    for _ in range(column_count):
      for j in range(row_count):
        table[j].append(message[k])
        k += 1

    print(tabulate(table, tablefmt="pretty"))
    for row in table:
      for i in range(column_count):
        result += row[i]
    print(f"Final string:\n{result}")


def perform_decryption():
    filename = input("Enter file to be decrypted: ")
    message = file_to_str(filename)
    key = recursive_read_int("Enter key value: ")
    result = ""

    table = []

    size = len(message)
    row_count = key
    column_count = math.ceil(size / key)
    extra_bits = row_count * column_count - size

    for _ in range(extra_bits):
      message += " "

    k = 0

    for _ in range(row_count):
      table.append([])
    
    for i in range(row_count):
      for _ in range(column_count):
        table[i].append(message[k])
        k += 1

    print(tabulate(table, tablefmt="pretty"))
    for i in range(column_count):
      for row in table:
        result += row[i]
    print(f"Final string:\n{result}")

is_encrypt = recursive_read(
    ["e", "d"], "Enter 'e' for encryption or 'd' for decryption: ") == "e"

if is_encrypt:
    perform_encryption()
else:
    perform_decryption()