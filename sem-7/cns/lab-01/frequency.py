def file_to_str(filename):
    try:
        with open(filename, 'r') as file:
            return file.read()
    except:
        print("Error: File not found!")
        exit(1)


filename = input("Enter file to be encrypted: ")
message = file_to_str(filename)

actual_frequency = "ETAOINHSRLDWMUYGCFPBKVJXQZ"

message_frequency = []

for i in range(26):

    message_frequency.append([chr(ord("A") + i), 0])


for charecter in message:
    if charecter.isalpha():
        message_frequency[ord(charecter.upper()) - ord("A")][1] += 1

message_frequency.sort(key=lambda x: x[1], reverse=True)

result = ""

for charecter in message:
    if charecter.isalpha():
      # TODO: Change to binary search
      for i in range(26):
        if message_frequency[i][0] == charecter.upper():
          result += actual_frequency[i]
          break
    else:
      result += charecter


print("Decrypted Message:\n")
print(result.lower())
