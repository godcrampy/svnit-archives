import socket

ClientSocket = socket.socket()
host = "127.0.0.1"
port = int(input("Select Port to connect to: "))

print("Waiting for connection")
try:
    ClientSocket.connect((host, port))
except socket.error as e:
    print(str(e))
    exit()
print("Connected to Master successfully. Enter messages. Press \"exit\" to quit")
Response = ClientSocket.recv(1024)
print(Response.decode())
try:
    while True:
        msg = input("Enter String:")
        if msg == "exit":
            exit()
        ClientSocket.send(msg.encode())
        res = ClientSocket.recv(1024).decode()
except Exception:
    ClientSocket.close()