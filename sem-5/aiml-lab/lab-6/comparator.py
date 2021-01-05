from city import City


class Comparator:
    def __init__(self, current: City, start_cost: int, end_cost: int):
        self.city = current
        self.start_cost = start_cost
        self.end_cost = end_cost

    def cost(self):
        return self.start_cost + self.end_cost

    def __lt__(self, other):
        return (self.cost()) - other.cost()
