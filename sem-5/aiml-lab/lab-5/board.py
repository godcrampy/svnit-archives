class Board:
    def __init__(self, state=[1, 2, 3, 8, 0, 4, 7, 6, 5]):
        # 0 implies empty state
        assert len(state) == 9
        self.value = state

    def __eq__(self, other):
        return self.value == other.value

    def __hash__(self):
        return "".join(str(x) for x in self.value).__hash__()

    def __lt__(self, other):
        return self.near_completion() < other.near_completion()

    def near_completion(self):
        complete = [1, 2, 3, 8, 0, 4, 7, 6, 5]
        completion = 9
        for i in range(9):
            if self.value[i] == complete[i]:
                completion -= 1
        return completion

    def _find_space(self):
        for i in range(9):
            if self.value[i] == 0:
                return i

    def is_left(self):
        location = self._find_space()
        if location in [0, 3, 6]:
            return False
        return True

    def is_right(self):
        location = self._find_space()
        if location in [2, 5, 8]:
            return False
        return True

    def is_up(self):
        location = self._find_space()
        if location in [0, 1, 2]:
            return False
        return True

    def is_down(self):
        location = self._find_space()
        if location in [6, 7, 8]:
            return False
        return True

    def up(self):
        state = list.copy(self.value)
        if not self.is_up():
            raise Exception(f"Up not possible, state: {self.value}")
        i = self._find_space()
        state[i], state[i - 3] = state[i - 3], state[i]
        return Board(state)

    def down(self):
        state = list.copy(self.value)
        if not self.is_down():
            raise Exception(f"Down not possible, state: {self.value}")
        i = self._find_space()
        state[i], state[i + 3] = state[i + 3], state[i]
        return Board(state)

    def left(self):
        state = list.copy(self.value)
        if not self.is_left():
            raise Exception(f"Left not possible, state: {self.value}")
        i = self._find_space()
        state[i], state[i - 1] = state[i - 1], state[i]
        return Board(state)

    def right(self):
        state = list.copy(self.value)
        if not self.is_right():
            raise Exception(f"Right not possible, state: {self.value}")
        i = self._find_space()
        state[i], state[i + 1] = state[i + 1], state[i]
        return Board(state)

    def expand(self):
        res = {}
        if self.is_left():
            res[self.left()] = "l"
        if self.is_right():
            res[self.right()] = "r"
        if self.is_up():
            res[self.up()] = "u"
        if self.is_down():
            res[self.down()] = "d"

        return res

    def print(self):
        print(f"{self.value[0]} | {self.value[1]} | {self.value[2]}")
        print(f"-   -   -")
        print(f"{self.value[3]} | {self.value[4]} | {self.value[5]}")
        print(f"-   -   -")
        print(f"{self.value[6]} | {self.value[7]} | {self.value[8]}")
        print()
