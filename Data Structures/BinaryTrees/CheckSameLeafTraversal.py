class Node:

    def __init__(self, data):
        self.data = data
        self.left = self.right = None

def leafTraversal(node, lst):
    if node is None:
        return
    if node is not None:
        leafTraversal(node.left, lst)
        if node.left is not None and node.right is not None:
            lst.append(node.data)
        leafTraversal(node.right, lst)

root1 = Node(1)
root1.left = Node(2)
root1.right = Node(3)
root1.left.left = Node(4)
root1.right.left = Node(6)
root1.right.right = Node(7)

root2 = Node(0)
root2.left =  Node(5)
root2.left.right =  Node(4)
root2.right = Node(8)
root2.right.left =  Node(6)
root2.right.right =  Node(7)

lst1 = []
lst2 = []

leafTraversal(root1, lst1)
leafTraversal(root2, lst2)

print(lst1 == lst2)
