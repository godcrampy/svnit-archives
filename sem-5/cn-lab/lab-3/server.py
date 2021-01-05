import socket
import os
import time
from _thread import *
import threading

print("Starting Server...")
ServerSocket = socket.socket()
host = "127.0.0.1"
port = int(input("Enter Server Port: "))
thread_count = 0
try:
    ServerSocket.bind((host, port))
except socket.error as e:
    print(f"Error: {e}")
    print("Closing Server...")
    exit

print("Waiting for a Connection..")
ServerSocket.listen(10)

res = "."


def listener():
    client, address = ServerSocket.accept()
    print("Master Connected")
    print("Connected to: " + address[0] + ":" + str(address[1]))
    client.send(str.encode("Welcome to the Server\n"))
    try:
        while True:
            global res
            data = client.recv(2048)
            msg = data.decode()
            if not data:
                print(f"Master shutting down.")
                break
            if msg != ".":
                print(f"Received from master: {msg}")
            client.sendall(res.encode())
            res = "."
    except Exception:
        client.close()


threads = []


def file_writer():
    while True:
        user_input = input()
        global res
        res = user_input
        if res == "exit":
            print("Closing Server...")
            exit()


t1 = threading.Thread(target=listener)
t2 = threading.Thread(target=file_writer)

t1.start()
time.sleep(0.1)
t2.start()

t1.join()
ServerSocket.close()
