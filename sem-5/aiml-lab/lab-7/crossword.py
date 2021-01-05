from cell import Cell
from enum import Enum


class Direction(Enum):
    HORIZONTAL = 0
    VERTICAL = 1


class Crossword:
    def __init__(self, grid):
        """
        grid specs:
            'X': Black
            '0': Empty
            '1': annotation
        """
        self.grid: list[list[Cell]] = []
        for row in grid:
            new_row = []
            for cell in row:
                if cell == "X":
                    new_row.append(Cell(True))
                elif cell == "0":
                    new_row.append(Cell())
                else:
                    new_row.append(Cell(False, True, int(cell)))
            self.grid.append(new_row)

    def print(self):
        for row in self.grid:
            for cell in row:
                print(cell, end=" ")
            print()
        print()

    def clone(self):
        res = Crossword([])
        grid = []
        for row in self.grid:
            new_row = []
            for cell in row:
                new_row.append(cell.clone())
            grid.append(new_row)
        res.grid = grid
        return res

    def _in_range(self, r: int, c: int) -> bool:
        return len(self.grid) > r and len(self.grid[r]) > c

    def can_fit(self, word: str, r: int, c: int, dir: Direction) -> bool:
        if not self._in_range(r, c):
            raise Exception("Coordinates out of bound")

        l = len(word)
        if dir == Direction.HORIZONTAL:
            for i in range(l):
                if not self._in_range(r, c + i):
                    return False
                cell: Cell = self.grid[r][c + i]
                if cell.is_black or (cell.value != " " and cell.value != word[i]):
                    return False

        if dir == Direction.VERTICAL:
            for i in range(l):
                if not self._in_range(r + i, c):
                    return False
                cell: Cell = self.grid[r + i][c]
                if cell.is_black or (cell.value != " " and cell.value != word[i]):
                    return False

        return True

    def is_filled(self):
        for row in self.grid:
            for cell in row:
                if cell.is_empty:
                    return False
        return True

    def fit(self, word: str, r: int, c: int, dir: Direction):
        if not self.can_fit(word, r, c, dir):
            raise Exception("Cannot fit word")

        l = len(word)
        if dir == Direction.HORIZONTAL:
            for i in range(l):
                cell: Cell = self.grid[r][c + i]
                cell.fill(word[i])

        if dir == Direction.VERTICAL:
            for i in range(l):
                cell: Cell = self.grid[r + i][c]
                cell.fill(word[i])
