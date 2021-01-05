from typing import Dict


class City:
    def __init__(self, x: int, y: int, name: str):
        self.x = x
        self.y = y
        self.name = name
        self.neighbours: Dict[City, float] = {}

    def __sub__(self, other):
        """Manhattea Distance"""
        return abs(self.x - other.x + self.y - other.y)

    def __hash__(self):
        return f"{self.x} {self.y}".__hash__()

    def __str__(self):
        return f"{self.name}{{{self.x} {self.y}}}"

    def print(self):
        return f"{self} => " + \
            " ".join(
                [f"({str(city)}, {self.neighbours[city]})" for city in self.neighbours])

    def connect(self, city, distance: int):
        self.neighbours[city] = distance
        city.neighbours[self] = distance
