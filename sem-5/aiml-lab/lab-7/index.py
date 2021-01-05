from crossword import Crossword, Direction

grid = [
    "10203",
    "XX0X0",
    "X4050",
    "6X700",
    "80000",
    "0XX0X"
]
c = Crossword(grid)


def solve(cwd: Crossword, words: list) -> True:
    if cwd.is_filled():
        print("Solved!")
        cwd.print()
        print(f"Unused words: {words}")
        return True

    if not words:
        return False

    words_copy = list.copy(words)
    word = words_copy.pop(0)
    r = len(cwd.grid)
    if r == 0:
        return False
    c = len(cwd.grid[0])

    for x in range(r):
        for y in range(c):
            if cwd.grid[x][y].is_black:
                next
            clone = cwd.clone()
            if clone.can_fit(word, x, y, Direction.HORIZONTAL):
                clone.fit(word, x, y, Direction.HORIZONTAL)
                if solve(clone, words_copy):
                    return True
            clone = cwd.clone()
            if clone.can_fit(word, x, y, Direction.VERTICAL):
                clone.fit(word, x, y, Direction.VERTICAL)
                if solve(clone, words_copy):
                    return True
            clone = cwd.clone()

    return False


words = ["hoses", "hike", "steer", "laser",
         "sails", "keel", "ale", "eel", "sheet", "heal", "line", "aft", "tie", "knot"]

if not solve(c, words):
    print("No Solution Found :(")
