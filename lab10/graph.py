class Graph:
    def __init__(self):
        # Using a dictionary to store the adjacency list.
        self.adjacency_list = {}
    
    def add_node(self, node):
        # Add the node if it doesn't exist already.
        if node not in self.adjacency_list:
            self.adjacency_list[node] = []
    
    def add_edge(self, src, dest):
        # Ensure both nodes exist.
        self.add_node(src)
        self.add_node(dest)
        
        # Add the edge from src to dest.
        self.adjacency_list[src].append(dest)

    def display(self):
        # Display the graph structure.
        for node, neighbours in self.adjacency_list.items():
            print(f"{node} -> {', '.join(map(str, neighbours))}")

    def order(self, start, dest):
        print("breadth-first-search: ")
        #implement bfs first
        counter = 0
        visited = []
        queue = []
        
        visited.append(start)
        queue.append(start)
        
        while queue:
            s = queue.pop(0)
            counter += 1
            if s == dest:
                print(counter)
            else:
                for n in self.adjacency_list[s]:
                    if n not in visited:
                        visited.append(n)
                        queue.append(n)
                 
        print("depth-first search:")
        counter = 0
        visited2 = []
        stack = []
        
        visited2.append(start)
        stack.append(start)
        
        while stack:
            s = stack.pop()
            counter += 1
            if s == dest:
                print(counter)
            else:
                for n in self.adjacency_list[s]:
                    if n not in visited2:
                        visited2.append(n)
                        stack.append(n)
            
            
# Example usage:
if __name__ == "__main__":
    graph = Graph()
    graph.add_edge("YYZ", "YVR")
    graph.add_edge("YVR", "YYZ")
    graph.add_edge("YVR", "YUL")
    graph.add_edge("YUL", "YXZ")
    graph.add_edge("YVR", "YXZ")
    
    # Display the graph's adjacency list.
    graph.order("YYZ", "YXZ")
