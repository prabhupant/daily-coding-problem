class Node:
    
    def __init__(self, data):
        self.data =data
        self.right = None
        self.left = None

def flipBinaryTree(root):

    if root is None:
        return root

    if root.left is None and root.right is None:
        return root

    flippedRoot = flipBinaryTree(root.left)
    root.left.left = root.right
    root.left.right = root
    root.left = root.right = None

    return flippedRoot

def printLevelOrder(root):
    
    if root is None:
        return

    queue = []

    queue.append(root)
    while(len(queue) > 0):
        print(queue[0].data)
        node = queue.pop(0)

        if node.left is not None:
            queue.append(node.left)
        if node.right is not None:
            queue.append(node.right)

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)


