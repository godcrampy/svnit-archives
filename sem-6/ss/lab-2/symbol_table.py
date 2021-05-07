import re
from symbol_field import SymbolField
from tabulate import tabulate
from termcolor import colored


class SymbolTable:
    def __init__(self, start: int):
        self.fields = []
        self.symbols = set()
        self.address = start

    def insert(self, line: str):
        if not re.match(r'\s', line):
            # starts with symbol
            symbol = line.split()[0]
            if symbol not in self.symbols:
                self.fields.append(SymbolField(symbol, self.address))
                self.symbols.add(symbol)
            else:
                print(
                    colored(f"Warning: symbol {symbol} already defined. Address = {self.address}", color="yellow"))
        self.address += 1

    def print(self):
        print(tabulate([[x.symbol, x.address]
                        for x in self.fields], headers=["Symbol", "Address"], tablefmt="psql"))
