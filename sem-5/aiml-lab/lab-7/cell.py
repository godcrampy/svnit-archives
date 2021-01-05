superscript_map = {
    "0": "⁰", "1": "¹", "2": "²", "3": "³", "4": "⁴", "5": "⁵", "6": "⁶",
    "7": "⁷", "8": "⁸", "9": "⁹"}


class Cell:
    def __init__(self, is_black: bool = False, is_annoted: bool = False, annotation: int = 0, ):
        self.is_black = is_black
        # Charecter in Cell, "0" => black cell, " " => empty cell
        self.value = " "
        # annotation is the number if any that the cell carries
        self.is_annoted = is_annoted
        self.annotation = annotation

    @property
    def is_empty(self):
        return self.value == " " and not self.is_black

    def clone(self):
        cell = Cell(self.is_black, self.is_annoted, self.annotation)
        cell.value = self.value
        return cell

    def __str__(self):
        value = self.value if self.value != "0" else " "
        if self.is_black:
            return "|" + 3 * u"\u2588" + "|"
        if self.is_annoted:
            return f"|{superscript_map[str(self.annotation)]} {value}|"
        return f"|  {value}|"

    def fill(self, charecter: str):
        if len(charecter) != 1:
            raise Exception("Length of charecter should be 1")
        self.value = charecter
