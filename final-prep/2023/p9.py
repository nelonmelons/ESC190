import heapq
class Node:
    def __init__(self, value):
        self.value = value
        self.connections = []


class Con:
    def __init__(self, node, cost):
        self.node = node
        self.cost = cost
#Con objects are appended to node.connections to represent its connectoins with weight


#construct graph and then use diekstra
def mincost(cost):
    n = len(cost)
    graph = [None] * (n+1)
    for i in range(n + 1):
        graph[i] = Node(i)
        graph[i].connections.extend([
            Con(i+1, cost[i+1]), 
            Con(i+2, cost[i+2]), 
            Con((i+3), cost[i+3])
        ])
        
    #now implement diakstras algo
    start = graph[0]
    start.distance = 0
    visited = set()
    tobeconsidered = [(0, {"node": start, "prev": None})]
    current = start
    while current != graph[n]:
        cur_dist, current_dict = heapq.heappop(tobeconsidered)
        current = current_dict["node"]
        prev = current_dict["prev"]
        current.prev = prev
        if current not in visited:
            current.distance = cur_dist
            visited.add(current)
            for con in current.connections:
                if con.node not in visited:
                    heapq.heappush(tobeconsidered, (con.cost + current.distance, {"node": con.node, "prev": current}))
    return current.distance