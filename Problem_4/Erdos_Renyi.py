import numpy as np
import matplotlib.pyplot as plt
from tqdm import trange

nodes: int = 1000
repeats: int = 1000
s_min: int = 1
p_k: np.ndarray = np.zeros(nodes)
k_max: int = 0
p: float = 1/6


def function():
    deg = np.zeros((nodes, nodes))
    for i in range(nodes):
        for j in range(nodes):
            num = np.random.rand()
            if num < p:
                deg[i][j] = 1
            else:
                continue

    S1 = np.sum(deg, axis=1)
    return S1


for _ in trange(repeats):
    S2 = function()
    s_max = int(S2.max())
    if s_max > k_max:
        k_max = s_max
    for value in range(s_min, s_max + 1):
        p_k[value] = p_k[value] + np.count_nonzero(S2 == value)


kappa = np.arange(s_min, k_max+1)

plt.figure(0)
plt.title("Erdos-Renyi Network with N=1000 nodes")
plt.plot(kappa, p_k[:k_max]/repeats)
plt.xlabel("k")
plt.ylabel("P(k)")
plt.show()
