class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def isBST(root):
    return isBSTUtil(root, INT_MIN, INT_MAX)

def isBSTUtil(node, low, high):
    if node is None:
        return True
    if node.data < low or node.data > high:
        return False
    return isBSTUtil(node.left, low, node.data - 1) and isBSTUtil(node.right, node.data + 1, high)


