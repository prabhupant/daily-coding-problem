class Node:

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def preorder(node):
    queue = []
    queue.append(node)
    while len(queue) > 0:
        temp = queue.pop(0)
        print(temp.data)
        if temp.left is not None:
            queue.append(temp.left)
        if temp.right is not None:
            queue.append(temp.right)
        
def mirror(node):
    if node is None:
        return node
    left = mirror(node.left)
    right = mirror(node.right)
    node.left = right
    node.right = left
    return node

root = Node(1)
root.left = Node(2)
root.right = Node(3)

preorder(root)
mirror(root)
preorder(root)
