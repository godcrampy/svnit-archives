from typing import List


def print_matrix(matrix: List[List[float]]) -> None:
    for row in matrix:
        for num in row:
            print("{:8.3f}".format(num), end=" ")
        print()
