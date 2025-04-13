class Node:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None
            
            
def sum_tree(node):
    if node is None:
        return 0
    return node.value + sum_tree(node.left) + sum_tree(node.right)

# Usage

       
        
root = Node(1)
root.left = Node(4)
root.right = Node(5)
root.right.left = Node(7)

print(root.right.left.value)
print(sum_tree(root))
    
        
    
