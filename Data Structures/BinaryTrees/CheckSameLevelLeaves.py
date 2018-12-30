class Node:

    def __init__(self, data):
        self.data = data
        self.left = self.right = None

def checkUtil(root, level):
    if root is None:
        return True

    if root.left is None and root.right is None:
        if check.leafLevel == 0:
            check.leafLevel = level
            return True
        return level == check.leafLevel

    return (checkUtil(root.left, level+1) and checkUtil(root.right, level+1))

def check(root):
    level = 0
    check.leafLevel = 0
    return checkUtil(root, level)


