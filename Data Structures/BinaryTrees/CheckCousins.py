class Node:
    
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def level(root, node, lev):

    if root is None:
        return 0
    if root is node:
        return lev
    l = level(root.left, node, lev + 1)
    if l is not 0:
        return l
    return level(root.right, node, lev + 1)

def isSibling(root, node1, node2):

    if root is None:
        return False
    return ((root.left is node1 and root.right is node2) or (root.right is node1 and root.left is node2) or isSibling(root.left, node1, node2) or isSibling(root.right, node1, node2))

def isCousin(root, node1, node2):
    
    if root is None:
        return False
    return level(root, node1, 1) == level(root, node2, 1) and not isSibling(root, node1, node2)


if __name__ == '__main__':
    root = Node(6)
    root.left = Node(3)
    root.right = Node(5)
    root.left.left = Node(7)
    root.left.right = Node(8)
    root.right.left = Node(1)
    root.right.right = Node(3)
    print(level(root, root.left.left, 1))
    print(isCousin(root, root.left.left, root.right))
    print(isCousin(root, root.left.left, root.right.right))

