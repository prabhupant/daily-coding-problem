class Node:

    def __init__(self, data):
        self.data = data
        self.left = self.right = None

def checkChildrenSum(node):
    
    left_data = 0
    right_data = 0

    if node is None or (node.left is None and node.right is None):
        return True
    else:
        if node.left is not None:
            left_data = node.left.data
        if node.right is not None:
            right_data = node.right.data
        if node.data == right_data + left_data and checkChildrenSum(node.left) and checkChildrenSum(node.right):
            return True
        else:
            return False


