import math
from random import randint, randrange
from typing import List
from particle import Particle
from config import vx_bound, vy_bound

class Swarm:
    def __init__(self, particles: List[Particle], matrix: List[List[float]]) -> None:
        self.particles = particles
        self.matrix = matrix
        self.x_len = len(matrix[0])
        self.y_len = len(matrix)

        # Assign a random position as global best
        self.current_global_best_position = self.particles[randrange(len(self.particles))].position
        self.current_global_best_value = self.evaluate_particle(self.current_global_best_position)
    
    def evaluate_particle(self, position: List[int]) -> int:
        return self.matrix[position[1]][position[0]]

    def update_global_best(self) -> None:
        for particle in self.particles:
            particle_value = self.evaluate_particle(particle.position)
            if particle_value < self.current_global_best_value:
                self.current_global_best_position = particle.position
                self.current_global_best_value = particle_value

            #update particle best position
            if particle_value < particle.fitness_value:
                particle.best_position = particle.position
                particle.fitness_value = particle_value

    def update_position(self) -> None:
        for particle in self.particles:
            # Update velocity
            # Add random component
            particle.velocity[0] += randint(-vx_bound, vx_bound)
            particle.velocity[1] += randint(-vy_bound, vy_bound)

            # Add particle best position component
            dx = particle.best_position[0] - particle.position[0]
            dy = particle.best_position[1] - particle.position[1]
            vector_length = math.sqrt(dx ** 2 + dy ** 2)
            if vector_length > 0:
                particle.velocity[0] += int(dx * vx_bound / vector_length)
                particle.velocity[1] += int(dy * vy_bound / vector_length)


            # Add global best position component
            dx = self.current_global_best_position[0] - particle.position[0]
            dy = self.current_global_best_position[1] - particle.position[1]
            vector_length = math.sqrt(dx ** 2 + dy ** 2)
            if vector_length > 0:
                particle.velocity[0] += int(dx * vx_bound / vector_length)
                particle.velocity[1] += int(dy * vy_bound / vector_length)

            # Update position
            particle.position[0] = particle.position[0] + particle.velocity[0]
            particle.position[1] = particle.position[1] + particle.velocity[1]

            # Check if position is out of bounds
            if particle.position[0] < 0:
                particle.position[0] = 0
            elif particle.position[0] >= self.x_len:
                particle.position[0] = self.x_len - 1

            if particle.position[1] < 0:
                particle.position[1] = 0
            elif particle.position[1] >= self.y_len:
                particle.position[1] = self.y_len - 1

    def update_particles(self) -> None:
        self.update_position()
        self.update_global_best()