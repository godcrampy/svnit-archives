class CostPath:
    def __init__(self, board, cost):
        self.board = board
        self.cost = cost

    def __lt__(self, other):
        return self.cost < other.cost
