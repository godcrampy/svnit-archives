from board import Board
from typing import Deque
import time
from collections import deque

board = Board()


def dfs():

    stack: Deque[Board] = deque()
    stack.append(board)
    max_size = len(stack)

    while stack:
        node = stack.pop()

        if node.is_solved():
            print("Found!")
            node.print()
            return max_size

        for i in range(Board.SIZE):
            new = node.add_queen(i + 1)
            if new.is_legal():
                max_size = max(max_size, len(stack))
                stack.append(new)

    print("Not Found!")
    return max_size


def bfs():

    queue: Deque[Board] = deque()
    queue.append(board)
    max_size = len(queue)

    while queue:
        node = queue.popleft()

        if node.is_solved():
            print("Found!")
            node.print()
            break

        for i in range(Board.SIZE):
            new = node.add_queen(i + 1)
            if new.is_legal():
                max_size = max(max_size, len(queue))
                queue.append(new)

    print("Not Found!")
    return max_size


print("DFS:")
start = time.time()
size = dfs()
print(f"Time taken: {time.time() - start}")
print(f"Memory taken: {size}")
print()
print("BFS:")
start = time.time()
size = bfs()
print(f"Time taken: {time.time() - start}")
print(f"Memory taken: {size}")
