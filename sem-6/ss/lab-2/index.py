import sys
import re
from termcolor import colored

from symbol_table import SymbolTable

if len(sys.argv) != 2:
    print("Usage: python index.py <file-name>")
    exit(1)

file_name = sys.argv[1]


address = int(input("Enter starting address: "))

st = SymbolTable(address)
with open(file_name) as f:
    lines = f.readlines()
    for line in lines:
        st.insert(line)

while True:
    c = input("""
Options:
  i: insert
  m: modify
  s: search
  d: display
  q: quit
  Your Choice: """)

    if c == "i":
        st.insert(input("Enter next instruction: "))
        print(colored(f"Inserted!", color="green"))

    elif c == "m":
        symbol = input("Enter symbol to modify: ")
        if symbol in st.symbols:
            addr = int(input("Enter new Address: "))
            for field in st.fields:
                if field.symbol == symbol:
                    field.address = addr
                    break
            print(colored(f"Modified!", color="green"))
        else:
            print(colored("Error: Symbol not found", color="red"))
    elif c == "s":
        symbol = input("Enter symbol to search: ")
        if symbol in st.symbols:
            for field in st.fields:
                if field.symbol == symbol:
                    print(colored(f"{symbol}: {field.address}", color="green"))
                    break
        else:
            print(colored("Error: Symbol not found", color="red"))
    elif c == "d":
        st.print()
    elif c == "q":
        break
    else:
        print("Error: Unknown Command")
