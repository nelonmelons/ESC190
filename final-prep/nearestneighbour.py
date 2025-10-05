import numpy as np

def euclidean_distance(a, b):
    return np.linalg.norm(a - b)

def predict(x_test, x_train, y_train):
    distances = [euclidean_distance(x_test, x) for x in x_train]
    closest_index = np.argmin(distances)
    return y_train[closest_index]



# dot product/ cosine similarity approach

import numpy as np

def cosine_similarity(a, b):
    dot = np.sum(a * b)
    norm_a = np.sqrt(np.sum(a * a))
    norm_b = np.sqrt(np.sum(b * b))
    if norm_a == 0 or norm_b == 0:
        return 0  # avoid division by zero
    return dot / (norm_a * norm_b)

def predict(x_test, x_train, y_train):
    sims = []
    for x in x_train:
        sim = cosine_similarity(x_test, x)
        sims.append(sim)
    sims = np.array(sims)
    closest_index = np.argmax(sims)  # pick the highest similarity (not lowest distance)
    return y_train[closest_index]

