import numpy as np
def sigma(x):
    return 1/(1 + np.exp(-x)) # sigmoid activation function

n_hid = 10 # number of hidden layers
x = np.random.rand(4096)
W0 = np.random.rand(1, 4096, n_hid)
W1 = np.random.rand(1, n_hid, 6) # size n_hid x n_hid x 6 (i.e. n_hid lists with n_hid entries and each entry is a list of 6 values)
b0 = np.random.rand(1, n_hid) 
b1 = np.random.rand(1, 6)  #size 1 x 6


hid = np.zeros((1, n_hid)) # size 1 x n_hid 
z = np.zeros((1, 6)) # size 1 x 6
#computation for the hidden layer (n_hid values)
for k in range(n_hid):
    for j in range(4096):
        hid[0][k] += W0[0, j, k] * x[j] # compute hidden layer output
    hid[0][k] += b0[0][k] # add bias value to hidden layer output
hid =  sigma(hid) # apply activation function to hidden layer output


#computation for the output layer(6 output values)
for k in range(6):
    #for j in range(4096):
    #    z[0][k] += W1[0, j, k] * hid[0, j] # compute output layer output
    z[0, k] = np.dot(W1[0, :, k], hid)
    z[0, k] += b1[0, k]
z = sigma(z) # apply activation function to output layer output

#so baiscally for hidden layer, its exactly like neural network but you're interating multiple times depending on how many layers u got. for each iteration, the output of the previous layer is the input for the next layer. (e.g. the z's become the x's. and u use those values to compute the next layer/output)


#given neural network, how to find the x's that activate a specific neuron the most?
# for example, if we want to find the x's that activate neuron 7 the most, we can do the following:
n_hid = 10

x = np.random.rand(4096)
# W is of size 1x4096x10
W0 = np.random.rand(1, 4096, n_hid)
W1 = np.random.rand(1, n_hid, 6)
b0 = np.random.rand(1, n_hid)
b1 = np.random.rand(1, 6)

x = np.random.rand(10000, 4096)
# for hidden neuron 7, find the x's that activate it the most
neuron7_acts = [] # list of all activations based on all x values
for i in range(10000):
    z, hid = nn(x[i], W0, W1, b0, b1, n_hid) #nn is function that returns z and hid values
    neuron7_acts.append((hid[0, 7], i))
neuron7_acts.sort(reverse=True)

# the top 10 activations are for x's at indices neuron7_acts[0][1], neuron7_acts[1][1], ...
for i in range(10):
    print(f"x[{neuron7_acts[i][1]}]")
