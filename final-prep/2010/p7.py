#adjacency list

class Graph:
    def __init__(self, v):
        self.list = {}
        for i in range(v):
            self.list[i] = []
    
    def insert(self, v1, v2):
        self.list[v1].append(v2)
        self.list[v2].append(v1)
    
    def hasEdge(self, v1, v2):
        if (v2 in self.list[v1]):
            return True
        return False
    
    def remove(self, v1, v2):
        self.list[v1].remove(v2)
        self.list[v2].remove(v1)
        
    def numEdges(self):
        count = 0
        for v in self.list:
            for e in self.list[v]:
                count += 1
        return count/2
    
    def delete(self):
        self.list = {}
