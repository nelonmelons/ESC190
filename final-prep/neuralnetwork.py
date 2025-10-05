# nearal network algo 
# basically you're computing dot product of weight vector and x vector(value) and adding bias value
# implementation:
    
import numpy as np
def sigma(x):
    return 1/(1 + np.exp(-x)) # sigmoid activation function

x = np.random.rand(4096) # random array of 4096 entries
W = np.random.rand(1, 4096, 6) # size 1 x 4096 x 6 (i.e. 1 list with 4096 entries and each entry is a list of 6 values)
# W[0][j][k] = weight for jth entry and kth value (i.e. 6 values for each entry)
b = np.random.rand(1, 6)  #size 1 x 6 
#1 list 6 values (1 x 6 vector) for bias
#z1 = sigma(sum(W1, j, 1) * x(j)) + b(1, 1)

z = np.zeros((1, 6)) # size 1 x 6
for k in range(6):
    for j in range(4096):
        z[0][k] += W[0][j][k] * x[j]
    z[0][k] += b[0][k] # add bias value to each entry in z
        
z = sigma(z) # apply activation function to z


import random
#graph implementation (of neural network):
class Node:
    def __init__(self, name, value=None):
        self.name = name
        self.value = value
        self.edges = []
    
    def add_edge(self, node, weight):
        self.edges.append({'node': node, 'weight': weight})
        
    def __repr__(self):
        return f"Node({self.name}, {self.value})"
    
def create_nn_graph(input_dim, output_dim):
    x = []
    z = []
    # Create input nodes
    for i in range(input_dim):
        node = Node(f"x{i}")
        x.append(node)
    for k in range(output_dim):
        node = Node(f"z{k}")
        z.append(node)
    for i in range(input_dim):
        for k in range(output_dim):
            weight = random.random() # random weight for edge
            x[i].add_edge(z[k], weight)
            z[k].add_edge(x[i], weight)
    