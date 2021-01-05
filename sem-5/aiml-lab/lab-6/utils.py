from city import City
import random
from typing import List


def random_number(start: int, end: int) -> int:
    return random.randint(start, end)


def connect_city_random(a: City, b: City):
    md = b - a
    d = random_number(md, 2 * md)
    a.connect(b, d)


def print_answer(title: str, arr: List):
    print(f"Solution for {title}: {arr}")
