import sys
import re
from termcolor import colored
from tabulate import tabulate

if len(sys.argv) != 3:
    print("Usage: python index.py <file-name> <file-name>")
    exit(1)

file_name = sys.argv[1]
macro_file = sys.argv[2]

ssn_tab = []
evn_tab = []
pn_tab = []
mdt = []  # label, opcode, operands


ssn_tab2 = []
evn_tab2 = []
pn_tab2 = []
mdt2 = []  # label, opcode, operands

address = 200


with open(macro_file) as f:
    for num, line in enumerate(f, 1):
        tokens = line.split()
        is_label_def = not bool(re.match(r'\s', line))
        if num != 1 and num != 2 and is_label_def:
            label = tokens[0]
            if label[0] == '&' and label not in evn_tab:
                evn_tab.append(label)
            elif label[0] == '.' and label not in ssn_tab:
                ssn_tab.append(label)

with open(macro_file) as f:
    for num, line in enumerate(f, 1):
        address += 1
        tokens = line.split()
        is_label_def = not bool(re.match(r'\s', line))
        if num == 1:
            print(line)
        elif num == 2:
            pn_tab = [x.split(',')[0].split('=')[0] for x in tokens[1:]]
            print(line)
        else:
            # fill mdt:
            row = ['', '', '']
            if is_label_def:

                label = tokens[0]
                tokens = tokens[1:]
                if label in evn_tab:
                    row[0] += f"(E, {evn_tab.index(label) + 1})"
                elif label in ssn_tab:
                    row[0] += f"(S, {ssn_tab.index(label) + 1})"

            row[1] = tokens[0]
            tokens = tokens[1:]

            res = ''
            for token in tokens:
                temp = token.split(',')[0]
                has_comma = (temp != token)
                token = temp
                if token in evn_tab:
                    res += f"(E, {evn_tab.index(token) + 1})"
                elif token in ssn_tab:
                    res += f"(S, {ssn_tab.index(token) + 1})"
                elif token in pn_tab:
                    res += f"(P, {pn_tab.index(token) + 1})"
                else:
                    res += token

                if has_comma:
                    res += ','

            row[2] = res
            row.insert(0, address)
            mdt2.append(row)

nested_macro = "ADDNUM"

with open(file_name) as f:
    for num, line in enumerate(f, 1):
        tokens = line.split()
        is_label_def = not bool(re.match(r'\s', line))
        if num != 1 and num != 2 and is_label_def:
            label = tokens[0]
            if label[0] == '&' and label not in evn_tab:
                evn_tab.append(label)
            elif label[0] == '.' and label not in ssn_tab:
                ssn_tab.append(label)

with open(file_name) as f:
    for num, line in enumerate(f, 1):
        address += 1
        tokens = line.split()
        is_label_def = not bool(re.match(r'\s', line))
        if num == 1:
            print(line)
        elif num == 2:
            pn_tab = [x.split(',')[0].split('=')[0] for x in tokens[1:]]
            print(line)
        else:
            # fill mdt:
            row = ['', '', '']
            if is_label_def:

                label = tokens[0]
                tokens = tokens[1:]
                if label in evn_tab:
                    row[0] += f"(E, {evn_tab.index(label) + 1})"
                elif label in ssn_tab:
                    row[0] += f"(S, {ssn_tab.index(label) + 1})"

            row[1] = tokens[0]
            tokens = tokens[1:]

            res = ''
            for token in tokens:
                temp = token.split(',')[0]
                has_comma = (temp != token)
                token = temp
                if token in evn_tab:
                    res += f"(E, {evn_tab.index(token) + 1})"
                elif token in ssn_tab:
                    res += f"(S, {ssn_tab.index(token) + 1})"
                elif token in pn_tab:
                    res += f"(P, {pn_tab.index(token) + 1})"
                else:
                    res += token

                if has_comma:
                    res += ','

            row[2] = res
            row.insert(0, address)
            mdt.append(row)


print(tabulate([[x] for x in pn_tab], headers=[
      colored("PN Table", color="yellow")], tablefmt="fancy_grid"))

print(tabulate([[x] for x in evn_tab], headers=[
    colored("EVN Table", color="yellow")], tablefmt="fancy_grid"))

print(tabulate([[x] for x in ssn_tab], headers=[
    colored("SSN Table", color="yellow")], tablefmt="fancy_grid"))

print()
print(colored("Macro Definition Table Initial", attrs=["bold"], color="blue"))
print(tabulate(mdt, headers=[colored("Addr", color="yellow"),
      colored("Label", color="yellow"), colored("Opcode", color="yellow"), colored("Operands", color="yellow")], tablefmt="fancy_grid"))

print(colored("Macro Definition Table Nested", attrs=["bold"], color="blue"))
print(tabulate(mdt2, headers=[colored("Addr", color="yellow"),
      colored("Label", color="yellow"), colored("Opcode", color="yellow"), colored("Operands", color="yellow")], tablefmt="fancy_grid"))


address = mdt[0][0]
for i in range(len(mdt)):
    x = i
    if(mdt[i][2] == nested_macro):
        mdt.pop(i)
        for r in mdt2:
            mdt.insert(x, r)
            x += 1

address = mdt[0][0]
for i in range(len(mdt)):
    mdt[i][0] = address
    address += 1


print(colored("Macro Definition Table Combined", attrs=["bold"], color="blue"))
print(tabulate(mdt, headers=[colored("Addr", color="yellow"),
      colored("Label", color="yellow"), colored("Opcode", color="yellow"), colored("Operands", color="yellow")], tablefmt="fancy_grid"))

