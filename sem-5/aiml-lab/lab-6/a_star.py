
from city import City
from comparator import Comparator
from heapq import heappush, heappop
from typing import Dict, List


class AStar:
    @classmethod
    def solve(self, start: City, end: City) -> List[str]:
        visited: Dict[City, List[str]] = {start: [start.name]}
        q: List[Comparator] = []
        heappush(q, Comparator(start, 0, end - start))

        while q:
            hc = heappop(q)
            city = hc.city
            start_cost = hc.start_cost
            path = visited[city]

            if city == end:
                return path

            for neighbour in city.neighbours:
                if neighbour not in visited and neighbour not in q:
                    heappush(q, Comparator(
                        neighbour, start_cost + 1, end - neighbour))
                    new_path = list.copy(path)
                    new_path.append(neighbour.name)
                    visited[neighbour] = new_path
