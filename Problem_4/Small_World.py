import numpy as np
import matplotlib.pyplot as plt
from tqdm import trange
from numba import jit


N: int = 1000
k: int = 14
p: float = 0.20
num_of_trials: int = 100
final: np.ndarray = np.zeros(N)


@jit(nopython=True, parallel=True)
def create_grid(nodes, connections):
    grid = np.zeros((nodes, nodes))
    for i in range(nodes):
        grid[int(i - connections / 2):i, i] = 1
        grid[-nodes + i + 1: -nodes + int(i + connections / 2 + 1), i] = 1
    return grid


def function(probability, grid_1, nodes):
    for i in range(nodes):
        for j in range(nodes):
            if grid_1[i][j] != 0:
                num_1 = np.random.rand()
                if num_1 <= probability:
                    grid_1[i][j] = 0
                    grid_1[j][i] = 0
                    scan = [value for value in range(nodes) if grid_1[i][value] == 0]
                    num_2 = np.random.choice(scan)
                    grid_1[i][num_2] = 1
                    grid_1[num_2][i] = 1
    degree = sum(grid_1)
    d = np.zeros(nodes)
    for value in range(nodes):
        d[int(degree[value])] += 1
    return grid_1, d


for trial in trange(num_of_trials):
    grid_2 = create_grid(N, k)
    [grid_2, d] = function(p, grid_2, N)
    final += d

final = final/num_of_trials
kappa = np.linspace(1, 50, 50)

plt.figure()
plt.plot(kappa, final[1:51])
plt.title("Small world network with N=1000 nodes and 100 repeats")
plt.xlabel("k")
plt.ylabel("P(k)")
plt.show()
