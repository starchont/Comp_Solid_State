import numpy as np
import matplotlib.pyplot as plt
from tqdm import trange
from numba import jit


# create a grid and fill it with zeros
@jit(nopython=True, parallel=False)
def grid_func(col, row):
    grid = [[0 for _ in range(col)] for _ in range(row)]
    grid[int(col / 2)][int(row / 2)] = 1
    first_pos = np.array([int(col / 2), int(row / 2)])
    return first_pos


def manhattan_lim(col, row, radi):
    limits = [[]]
    for i in range(col):
        for j in range(row):
            if abs(i - col / 2) + abs(j - row / 2) == radi:
                limits.append([i, j])
    return limits


def boarders(x, y, low, high):
    if x + 1 < low or y + 1 > high or x < low or y > high:
        return 1


def check_pos(arr, x, y):
    if [x + 1, y] in arr:
        arr.append([x, y])
        return 1
    if [x - 1, y] in arr:
        arr.append([x, y])
        return 1
    if [x, y + 1] in arr:
        arr.append([x, y])
        return 1
    if [x, y - 1] in arr:
        arr.append([x, y])
        return 1


# Creating matrices to save the occupied positions
occupied_positions = []

# Find the center and fill the matrices with the coordinates
center = grid_func(450, 450)
occupied_positions.append([center[0], center[1]])
start_positions = manhattan_lim(450, 450, 200)
repeat_num = 100000

# Starting random walk
for k in trange(repeat_num):
    seed = np.random.seed(4396 + k)
    num = np.random.randint(low=1, high=len(start_positions) - 1)
    start = start_positions[num][0]
    start_1 = start_positions[num][1]
    while True:
        if boarders(start, start_1, 0, 450):
            break
        num_1 = np.random.rand()
        if num_1 < 0.25:
            if boarders(start, start_1, 0, 450):
                break
            if check_pos(occupied_positions, start, start_1):
                break
            start = start + 1
        elif num_1 < 0.5:
            if boarders(start, start_1, 0, 450):
                break
            if check_pos(occupied_positions, start, start_1):
                break
            start = start - 1
        elif num_1 < 0.75:
            if boarders(start, start_1, 0, 450):
                break
            if check_pos(occupied_positions, start, start_1):
                break
            start_1 = start_1 + 1
        else:
            if boarders(start, start_1, 0, 450):
                break
            if check_pos(occupied_positions, start, start_1):
                break
            start_1 = start_1 - 1

x = []
y = []

# Saving values from list to fill scatter
for i in range(1, len(occupied_positions)):
    x.append(occupied_positions[i][0])
    y.append(occupied_positions[i][1])

L = np.linspace(10, 100, 5)
M = np.zeros(10)
Num = 20
N = 450

for _ in range(1, Num+1):
    x = int(N/2+np.random.randint(-L[0], L[0]+1))
    y = int(N/2+np.random.randint(-L[0], L[0]+1))
    index = 0
    for t in L:
        center_1 = int(t/2)
        for i in range(-center_1, center_1 + 1):
            for j in range(-center_1, center_1 + 1):
                if [i, j] in occupied_positions:
                    M[index] += 1
        index += 1

M = M/Num
df = (np.log10(M[9])-np.log10(M[0]))/(np.log10(L[9])-np.log10(L[0]))
print("The Dimension of Fractal is ", df)


# ******************************************************END*OF*RANDOM*WALK**************************************************

# Plot the results
fig = plt.figure(1)
ax = plt.axes()
plt.scatter(x, y, color="r")

fig_1 = plt.figure(2)
plt.scatter(np.log10(L), np.log10(M))
plt.xlabel("$log_{10}(L)$")
plt.ylabel("$log_{10}(M)$")

plt.show()

