import socket

print("Starting Server...")
ServerSocket = socket.socket()
host = "127.0.0.1"
port = int(input("Enter Receiving Port: "))
thread_count = 0

try:
    ServerSocket.bind((host, port))
except socket.error as e:
    print(f"Error: {e}")
    print("Closing Server...")
    exit

print("Waiting for a Connection..")
ServerSocket.listen(10)

connection, address = ServerSocket.accept()
print("Client Connected")
print("Connected to: " + address[0] + ":" + str(address[1]))

connection.send("Connected to Server".encode())

try:
    while True:
        data = connection.recv(2048)
        client_res = data.decode()
        print(client_res)
        connection.sendall(".".encode())
except Exception:
    connection.close()
