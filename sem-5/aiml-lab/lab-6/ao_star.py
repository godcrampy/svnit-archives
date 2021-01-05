from typing import Dict, List
from city import City
import math


class AOStar:
    @classmethod
    def solve(self, cities: Dict[str, City], start: City, end: City):
        visited1: Dict[City, List[str]] = {start: [start.name]}
        visited2: Dict[City, List[str]] = {start: [start.name]}
        or_res = self._solve_or(visited1, start, end)

        cities_list = list(cities.keys())
        and_res = self._solve_and(
            visited2, cities[cities_list[0]], cities[cities_list[1]], end)
        if len(and_res) == 0 or len(and_res) > len(or_res):
            return or_res
        return and_res

    @classmethod
    def _solve_or(self, visited: Dict[City, List[str]], start: City, end: City) -> List[str]:
        if start == end:
            return visited[start]

        path = visited[start]
        res = []
        min_length = math.inf
        for neighbour in start.neighbours:
            if neighbour not in visited:
                new_path = list.copy(path)
                new_path.append(neighbour.name)
                visited[neighbour] = new_path
                temp = self._solve_or(visited, neighbour, end)
                if len(temp) < min_length and len(temp) != 0:
                    res = temp
                    min_length = len(res)

        return res

    @classmethod
    def _solve_and(self, visited: Dict[City, List[str]], start1: City, start2: City, end: City) -> List[str]:
        first = self._solve_or(visited, start1, end)
        second = self._solve_or(visited, start2, end)

        if len(first) < len(second):
            return first
        return second
