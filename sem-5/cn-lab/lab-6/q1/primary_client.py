import socket
import os
from _thread import *
import threading
import time

print("Starting Primary Client...")
ServerSocket = socket.socket()
host = "127.0.0.1"
port = int(input("Enter Receiving Port: "))
thread_count = 0

try:
    ServerSocket.bind((host, port))
except socket.error as e:
    print(f"Error: {e}")
    print("Closing Primary Client...")
    exit

print("Waiting for a Connection..")
ServerSocket.listen(10)

msg = "."  # messages comming from slaves
res = "."  # messags coming from server


def comm():
    ClientSocket = socket.socket()
    host = "127.0.0.1"
    port = int(input("Select Server Port to connect to: "))

    print("Waiting for connection")
    try:
        ClientSocket.connect((host, port))
    except socket.error as e:
        print(str(e))
        exit()
    print("Connected to Server successfully.")
    Response = ClientSocket.recv(1024)
    try:
        while True:
            global res
            global msg
            # msg = ""
            time.sleep(1)
            # read from file
            # with open(name, "r") as f:
            # msg = f.read()
            # with open(name, "w") as f:
            # f.write(".")
            if res == "exit":
                exit()
            if msg != ".":
                print(f"Sending: {msg}")
            ClientSocket.send(msg.encode())
            res = ClientSocket.recv(1024).decode()
            if res != ".":
                print(f"Server Responded with: {res}")
            msg = "."
    except Exception:
        ClientSocket.close()


def threaded_client(connection, client_no):
    connection.send(str.encode("Welcome to the Server\n"))
    try:
        while True:
            global msg
            global res
            data = connection.recv(2048)
            client_res = data.decode()
            if not data:
                print(f"Client {client_no} shutting down.")
                break
            if client_res != ".":
                print(f"Received from client {client_no}: {msg}")
                msg = f"Client {client_no}[{client_res}]"
            connection.sendall(res.encode())
    except Exception:
        connection.close()


threads = []

t1 = threading.Thread(target=comm)
t1.start()
time.sleep(0.1)

while True:
    client, address = ServerSocket.accept()
    print("New Client Connected")
    print("Connected to: " + address[0] + ":" + str(address[1]))
    thread_count += 1
    t = threading.Thread(target=threaded_client, args=(client, thread_count))
    t.start()
    threads.append(t)
    print(f"Threads: {threads}")
    print(f"Thread Number: {thread_count}")
ServerSocket.close()
