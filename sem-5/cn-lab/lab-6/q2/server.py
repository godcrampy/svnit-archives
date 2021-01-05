import socket
import os
from _thread import *
import threading
import time
from typing import List

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

msg = "."  # messages coming from clients


def solve(ops: List[str]) -> str:
    error = "Error: Invalid Syntax"
    if not ops:
        return error
    operation = ops[0]
    if len(ops) == 3 and operation == "concat":
        return ops[1] + ops[2]
    if len(ops) == 2:
        operand = ops[1]
        if operation == "upper":
            return operand.upper()
        if operation == "lower":
            return operand.lower()
        if operation == "reverse":
            return operand[::-1]
        if operation == "len":
            return str(len(operand))
    return error


def threaded_client(connection, client_no):
    connection.send(
        """
      Welcome to String as a Service Server!
      Supported Operations:
        concat X Y
        upper X
        lower X
        reverse X
        len X
      """.encode()
    )
    try:
        while True:
            global msg
            res = "."
            data = connection.recv(2048)
            client_res: str = data.decode()
            if not data:
                print(f"Client {client_no} shutting down.")
                break
            if client_res != ".":
                print(f"Received from client {client_no}: {msg}")
                ops = client_res.split(" ")
                print(f"DEBUG: {ops}")
                msg = f"Client {client_no}[{client_res}]"
                res = solve(ops)
            connection.sendall(res.encode())
    except Exception:
        connection.close()


threads = []

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
