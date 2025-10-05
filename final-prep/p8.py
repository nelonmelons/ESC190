

def canBeSegmented(s, wordDict):
    n = len(s) + 1
    dp = [False] * n
    dp[0] = True
    
    for i in range(1, n):
        for j in range(0, i):
            if dp[j] is True and s[j:i] in wordDict:
                dp[i] = True
                break
    return dp[n-1]


s = "penapplepen"
wordDict = ["pen", "apple"]
print(canBeSegmented(s, wordDict))    

#DFS

def dfs(graph, start):
    stack = [start]
    visited = []
    while len(stack) > 0:
        node = stack.pop()
        if node not in visited:
            visited.append(node)
            for con in node.connections:
                if con not in visited:
                    stack.append(con)
    return visited


def bfs(graph, start):
    queue = [start]
    visited = []
    while len(queue) > 0:
        node = queue.pop(0)
        if node not in visited:
            visited.append(node)
            for con in node.connections:
                if con not in visited:
                    queue.append(con)
    return visited

import heapq

def dijkstra(graph, start):
    # distances stores the minimum distance found so far to each node.
    distances = {node: float('inf') for node in graph}
    distances[start] = 0

    # prev stores the previous node in the shortest path.
    prev = {node: None for node in graph}

    # Priority queue: (distance, node)
    queue = [(0, start)]
    
    while queue:
        current_distance, current_node = heapq.heappop(queue)

        # If the distance in the queue is not up-to-date, skip it.
        if current_distance > distances[current_node]:
            continue

        for neighbor, weight in graph.get(current_node, []):
            distance = current_distance + weight
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                prev[neighbor] = current_node
                heapq.heappush(queue, (distance, neighbor))
    
    return distances, prev

# Function to reconstruct the shortest path from start to target:
def reconstruct_path(prev, start, target):
    path = []
    current = target
    while current is not None:
        path.append(current)
        current = prev[current]
    path.reverse()
    return path

# Example usage:
print("\nDijkstra's Algorithm:")
distances, prev = dijkstra(graph, "A")
print("Distances:", distances)
# Example: reconstruct path from A to F:
path = reconstruct_path(prev, "A", "F")
print("Path from A to F:", path)


def bfs(graph, root):
    visited = []
    queue = [root]
    while queue:
        node = queue.pop(0)
        if node not in visited:
            visited.append(node)
            for connections in node.connections:
                if connections not in visited:
                    queue.append(connections)
    