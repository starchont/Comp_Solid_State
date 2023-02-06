import numpy as np
import matplotlib.pyplot as plt
import tqdm


def y(x, g, N):
    y_max = N-1
    y_min = 1
    return ((y_max**(1-g) - y_min**(1-g))*x+y_min**(1-g))**(1/(1-g))


def prob(kappa, N):
    degrees = np.zeros(N)
    for value in range(N):
        degrees[int(kappa[value])] += 1
    return degrees


iter_1: int = 10000
nodes: int = 10000
gamma: np.ndarray = np.array([2, 2.5, 3])
ind: int = 0


for i in gamma:
    histdata: np.ndarray = np.zeros(nodes)
    k_max = 0
    for value_1 in range(iter_1):
        x = np.random.rand()
        k = np.round(y(x, i, nodes))
        histdata[int(k)] = histdata[int(k)]+1
        if k > k_max:
            k_max = k
    k_plot = np.arange(1, k_max+1, 1)
    plt.figure(0)
    plt.scatter(np.log(k_plot[:int(k_max)]), np.log(histdata[:int(k_max)]), label="γ = " + str(i))
    plt.figure(ind+1)
    plt.scatter(np.log(k_plot[:int(k_max)]), np.log(histdata[:int(k_max)]), label="γ = " + str(i))
    ind += 1

plt.figure(0)
plt.legend()
plt.title("for all γ: Power law network for N=10000 nodes")
plt.xlabel("k")


plt.figure(1)
plt.legend()
plt.title("for γ = 2")

plt.figure(2)
plt.legend()
plt.title("for γ = 2.5")

plt.figure(3)
plt.legend()
plt.title("for γ = 3")

plt.show()
