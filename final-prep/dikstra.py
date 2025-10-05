import numpy as np

class Node:
    def __init__(self, value):
        self.value = value
        self.connections = []
        self.distance_from_start = np.inf # initalized to infinity . exactly what it sounds like

class Con:
    def __init__(self, node, weight):
        self.node = node
        self.weight = weight


# very similar to dfs/bfs,
#dijkstra without pq. (O{V^2} time complexity)
def dijkstra(start, end):
    start.distance_from_start = 0
    visited = set([start])
    current = start
    while current != end:
        
        cur_dist = np.inf # the shortest connections (distance) of the current node
        cur_v = None  #the node with closest distance in current node connections
        for node in visited:
            for con in node.connections:
                if con.node not in visited:
                    if cur_dist > node.distance_from_start + con.weight:
                        cur_dist = node.distance_from_start + con.weight
                        cur_v = con.node
        current = cur_v
        current.distance_from_start = cur_dist
        visited.add(current)
    return current.distance_from_start


def dikstra2practice(start, end):
    visited = set([start])
    current = start
    start.distance_from_start = 0
    while current != end:
        cur_v = None
        curdist = float('inf')
        for node in visited:
            for con in node.connections:
                if con.node not in visited:
                    if curdist > con.weight + node.distance_from_start:
                        curdist = con.weight + node.distance_from_start
                        cur_v = con.node
        current = cur_v
        current.distance_from_start = curdist
        visited.add(current) # min distance is finalized
    return current.distance_from_start #current here is the end / destination
            
        
    
class Node:
    def __init__(self, val):
        self.val = val
        self.connections = []
        self.distance_from_start = float('inf')
        
class Con:
    def __init__(self, node, weight):
        self.node = node
        self.weight = weight


def diakstraaaaaaaa(start, end):
    visited = set([start])
    current = start
    start.distance_from_start = 0
    
    while current != end:
        min_dist = float('inf')
        cur_v = None
        for node in visited:
            for con in node.connections:
                if con.node not in visited:
                    if min_dist > con.weight + node.distance_from_start:
                        min_dist = con.weight + node.distance_from_start
                        cur_v = con.node
        current = cur_v
        current.distance_from_start = min_dist
        visited.add(current)
    return current.distance_from_start
def diikkstra_final(start, end):
    start.distance_from_start = 0
    current = start
    visited = set([start])
    while current != end:
        mindist = float('inf')
        cur_v = None
        for node in visited:
            for con in node.connections:
                if con.node not in visited:
                    i
                




# FOR A*, ONLY DIFFERENCE IS WHEN APPENDING TO THE PQ, U ADD THE DISTANCE FROM START + HEURISTIC DISTANCE TO END NODE. (i.e. u add the heuristic distance to the distance from start to the node ur adding to the pq)

import heapq
# dijkstra with pq. (O{E + VlogV} time complexity)
class Node:
    def __init__(self, value):
        self.value = value
        self.connections = []
        self.distance_from_start = np.inf

class Con:
    def __init__(self, node, weight):
        self.node = node
        self.weight = weight

yyz = Node("YYZ")
lax = Node("LAX")
yul = Node("YUL")
yyz.connections.append(Con(lax, 1000))
yyz.connections.append(Con(yul, 300))


def dijkstra(start, end):
    start.distance_from_start = 0
    visited = set()
    to_be_considered = [(0, start)]
    current = start
    while current != end:
        
        cur_dist, current = heapq.heappop(to_be_considered)
        if current in visited:
            continue
        current.distance_from_start = cur_dist
        visited.add(current)
        for con in current.connections:
            if con.node in visited:
                continue
            heapq.heappush(to_be_considered, (con.weight + current.distance_from_start + .....(here u could add the heuristic function, making this effective A*), con.node))

    return current.distance_from_start

#not pq method
                                                