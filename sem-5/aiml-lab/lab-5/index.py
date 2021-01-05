from board import Board
from collections import deque
import heapq
from typing import Deque, Dict, List
from cost_path import CostPath


def bfs(start):
    # start = Board([2, 8, 1, 0, 4, 3, 7, 6, 5])
    # start = Board([1, 2, 3, 0, 8, 4, 7, 6, 5])
    goal = Board()

    q: Deque[Board] = deque()
    m: Dict[Board, List[str]] = {start: []}
    q.append(start)

    while q:
        node = q.popleft()
        path = m[node]

        if node == goal:
            print("Found!")
            print(path)
            return

        neighbours = node.expand()

        for neighbour in neighbours:
            if neighbour not in m:
                q.append(neighbour)
                newPath = list.copy(path)
                newPath.append(neighbours[neighbour])
                m[neighbour] = newPath


def dfs(start):
    # start = Board([2, 8, 1, 0, 4, 3, 7, 6, 5])
    goal = Board()

    q: Deque[Board] = deque()
    m: Dict[Board, List[str]] = {start: []}
    q.append(start)

    while q:
        node = q.pop()
        path = m[node]

        if node == goal:
            print("Found!")
            print(path)
            return

        neighbours = node.expand()

        for neighbour in neighbours:
            if neighbour not in m:
                q.append(neighbour)
                newPath = list.copy(path)
                newPath.append(neighbours[neighbour])
                m[neighbour] = newPath


def gbfs(start):
    goal = Board()

    q = []
    m: Dict[Board, List[str]] = {start: []}
    heapq.heappush(q, start)

    while q:
        node = heapq.heappop(q)
        path = m[node]

        if node == goal:
            print("Found!")
            print(path)
            return

        neighbours = node.expand()

        for neighbour in neighbours:
            if neighbour not in m:
                heapq.heappush(q, neighbour)
                newPath = list.copy(path)
                newPath.append(neighbours[neighbour])
                m[neighbour] = newPath


def ucs(start):
    goal = Board()

    q = []
    m: Dict[Board, List[str]] = {start: []}
    heapq.heappush(q, CostPath(start, 0))

    while q:
        cp = heapq.heappop(q)
        node = cp.board
        cost = cp.cost
        path = m[node]

        if node == goal:
            print("Found!")
            print(path)
            return

        neighbours = node.expand()

        for neighbour in neighbours:
            if neighbour not in m:
                heapq.heappush(q, CostPath(neighbour, cost + 1))
                newPath = list.copy(path)
                newPath.append(neighbours[neighbour])
                m[neighbour] = newPath


start = Board().up().right().down().down().left().left().up()

print("BFS:")
bfs(start)
print("DFS:")
dfs(start)
print("UCS:")
ucs(start)
print("GBFS:")
gbfs(start)
