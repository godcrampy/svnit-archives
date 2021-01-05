
def charecter_stuffing(flag: str, escape: str, data: str) -> str:
    x = data.replace(escape, escape*2)
    y = x.replace(flag, escape+flag)
    return flag + y + flag


flag = input("Enter Flag Character: ")
escape = input("Enter Escape Character: ")
data = input("Enter Data: ")

final = charecter_stuffing(flag, escape, data)

print(final)
