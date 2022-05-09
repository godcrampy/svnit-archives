import math
from random import randrange, uniform, randint

import numpy as np
from util import print_matrix
from swarm import Swarm
from particle import Particle
import seaborn as sns
import matplotlib.pyplot as plt
from scipy import interpolate
from simpy import Environment

from config import particle_count, x_bound, y_bound, vx_bound, vy_bound, threshold, max_iterations, matrix_val_range

matrix = [[uniform(0, matrix_val_range) for x in range(x_bound)] for y in range(y_bound)]


lst = []
for row in matrix:
    for num in row:
        lst.append(num)

lst.sort()

# Initialize particles with random velocities
particles = [Particle([randrange(0, x_bound), randrange(0, y_bound)], [
                      randint(-vx_bound, vx_bound), randint(-vy_bound, vy_bound)]) for i in range(particle_count)]

print('Initializing swarm...')
for particle in particles:
    print(particle)

swarm = Swarm(particles, matrix)
print(swarm.current_global_best_position)
print(swarm.current_global_best_value)

x = []
y = []
itr = 1

def tick():
    global itr
    itr += 1

env = Environment()
env.tick = tick

print()
print('Starting optimization...')
while itr < max_iterations:
    print(f'Iteration {itr}: Fitness Value = {swarm.current_global_best_value / itr}')
    print(f'    Global Best Position = {swarm.current_global_best_position}')
    swarm.update_particles()
    x.append(itr)
    y.append(swarm.current_global_best_value / itr)
    env.tick()
    best_rank = math.inf

    for i, v in enumerate(lst):
        if v >= swarm.current_global_best_value:
            best_rank = i + 1
            break
    current_threshold = 100 - (best_rank * 100 / len(lst))
    if current_threshold >= threshold:
        break


best_rank = math.inf

for i, v in enumerate(lst):
    if v >= swarm.current_global_best_value:
        best_rank = i + 1
        break

# Smoothen curve
x_new = np.linspace(1, itr, 1000)
bspline = interpolate.make_interp_spline(x, y)
y_new = bspline(x_new)

sns.lineplot(x_new, y_new).set(title='Change in cost over iterations', xlabel='Iteration', ylabel='Total Cost of Computation (Cents)')

print()
print('Matrix (X axis Compute Cost, Y axis Storage Cost):')
print_matrix(matrix)
print()
print('Optimization complete!')
print(f'Global Best Position = {swarm.current_global_best_position}')
print(f'Position of Particles:')
for i, particle in enumerate(swarm.particles):
    print(f'Task #{i + 1}: Compute Unit {particle.best_position[0]}, Storage Unit {particle.best_position[1]} ->', particle)

print()
plt.show()