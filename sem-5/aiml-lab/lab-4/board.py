class Board:
    SIZE = 8

    def __init__(self, state = None):
        if state is None:
            state = [0] * self.SIZE
        # 0 implies not set
        assert len(state) == self.SIZE
        self.state = state

    def __eq__(self, other):
        return self.state == other.state

    def is_full(self):
        for i in self.state:
            if i == 0:
                return False
        return True

    def is_legal(self):
        for i in range(self.SIZE):
            for j in range(i + 1, self.SIZE):
                if self.state[i] != 0 and self.state[j] != 0 and self.state[i] == self.state[j]:
                    return False
                if self.state[i] != 0 and self.state[j] != 0 and j - i == abs(self.state[i] - self.state[j]):
                    return False

        return True

    def is_solved(self):
        if not self.is_full():
            return False

        # no zeros


        # no same columns
        if len(self.state) != len(set(self.state)):
            return False

        # no same diagonals
        for i in range(self.SIZE):
            for j in range(i + 1, self.SIZE):
                if j - i == abs(self.state[i] - self.state[j]):
                    return False

        return True

    def print(self):
        for i in range(self.SIZE):
            row = ""
            for j in range(self.SIZE):
                if self.state[i] - 1 == j:
                    row += "Q "
                else:
                    row += "* "
            print(row)
        print()

    def add_queen(self, num):
        new_state = list.copy(self.state)
        for i in range(self.SIZE):
            if self.state[i] == 0:
                new_state[i] = num
                break
        return Board(new_state)
