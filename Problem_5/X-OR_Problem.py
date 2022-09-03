import numpy as np
from tqdm import trange


np.random.seed(4396)


def phi(x):
    return 1 / (1 + np.exp(-x))


def phi_derivative(x):
    return x * (1 - x)


# Input datasets
inputs = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
GT = np.array([[0], [1], [1], [0]])

epochs: int = 10000
n: float = 0.2
nodes_of_input_layer: int = 2
nodes_of_hidden_layer: int = 2
nodes_of_output_layers: int = 1
error_acc = 0.01

# Random initialization of weights and bias
hidden_weights = np.random.uniform(low=-1, high=1, size=(nodes_of_input_layer, nodes_of_hidden_layer))
hidden_bias = np.random.uniform(low=-1, high=1, size=(1, nodes_of_hidden_layer))
output_weights = np.random.uniform(low=-1, high=1, size=(nodes_of_hidden_layer, nodes_of_output_layers))
output_bias = np.random.uniform(low=-1, high=1, size=(1, nodes_of_output_layers))

# Training algorithm
for _ in trange(epochs):
    # Calculations for hidden layer
    u_for_hidden_layer = np.dot(inputs, hidden_weights)
    u_for_hidden_layer += hidden_bias
    hidden_layer_output = phi(u_for_hidden_layer)

    # Calculations for output layer
    u_for_output_layer = np.dot(hidden_layer_output, output_weights)
    u_for_output_layer += output_bias
    y = phi(u_for_output_layer)

    # Backpropagation
    error = GT - y
    delta_for_output_layer = error * phi_derivative(y)
    delta_for_other_layers = delta_for_output_layer.dot(output_weights.T) * phi_derivative(hidden_layer_output)
    output_weights += hidden_layer_output.T.dot(delta_for_output_layer) * n
    output_bias += np.sum(delta_for_output_layer) * n
    hidden_weights += inputs.T.dot(delta_for_other_layers) * n
    hidden_bias += np.sum(delta_for_other_layers) * n
    error_1 = 0.5 * np.abs(error)**2
    if error_1.all() <= error_acc:
        break

print("Final hidden weights: ", hidden_weights)
print("Final hidden bias : ", hidden_bias)
print("final bias: ", output_bias)
print("Final output weights: ", output_weights)
print("Final output", y)
