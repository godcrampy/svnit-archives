import rpyc

conn = rpyc.connect("localhost", 12345)

while True:
    print("Select option:")
    c = input("""
    q. Quit Program
    1. String is palindrome or not
    2. Is the year a leap year or not
    3. GCD of the given two numbers
    4. Square root of a given number
    5. Swap two variables
    6. Maximum, Minimum, average of given array
    7. Compare two strings
    8. Is string substring or not
    9. Concatenate two strings
    10. Reverse the elements of an array
    """)

    if c == "q":
        break
    elif c == "1":
        s = input("Enter string to test: ")
        print(f"Palindrome: {conn.root.is_palindrome(s)}")
    elif c == "2":
        year = int(input("Enter the year: "))
        print(f"Leap year: {conn.root.is_leap_year(year)}")
    elif c == "3":
        a = int(input("Enter number 1: "))
        b = int(input("Enter number 2: "))
        print(f"GCD: {conn.root.gcd(a, b)}")
    elif c == "4":
        a = int(input("Enter a number: "))
        print(f"Square Root: {conn.root.sqrt(a)}")
    elif c == "5":
        a = int(input("Enter number 1: "))
        b = int(input("Enter number 2: "))
        print(conn.root.swap_variables(a, b))
    elif c == "6":
        l = [int(x) for x in input("Enter space separated numbers: ").split()]
        print(l)
        print(conn.root.min_max_avg(l))
    elif c == "7":
        s1 = input("Enter string 1: ")
        s2 = input("Enter string 2: ")
        print(f"{s1} comes before {s2}: {conn.root.compare_strings(s1, s2)}")
    elif c == "8":
        s1 = input("Enter string 1: ")
        s2 = input("Enter string 2: ")
        print(f"{s1} is substring of {s2}: {conn.root.is_substring(s1, s2)}")
    elif c == "9":
        s1 = input("Enter string 1: ")
        s2 = input("Enter string 2: ")
        print(conn.root.concat_strings(s1, s2))
    elif c == "10":
        l = [int(x) for x in input("Enter space separated numbers: ").split()]
        print(conn.root.reverse_array(l))
