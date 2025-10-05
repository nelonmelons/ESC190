class Graph:
    def __init__(self, root):
        self.list = {root: []}
        
    def add_node(self, node):
        if node not in self.list:
            self.list[node] = []
    
    def add_con(self, node1, node2):
        