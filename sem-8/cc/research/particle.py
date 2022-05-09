from typing import List
from config import matrix_val_range


class Particle:
    def __init__(self, position: List[int], velocity: List[int]) -> None:
        self.position = position
        self.velocity = velocity
        self.best_position = position
        self.fitness_value = matrix_val_range

    def __str__(self) -> str:
        return f'Particle(position={self.position}, best_position={self.best_position}, fitness_value={self.fitness_value})'
