class Node:

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def morrisTraversal(root):

    if root is None:
        return
    curr = root

    while(curr is not None):
        if curr.left is None:
            print(curr.data)
            curr = curr.right
        else:
            pre = curr.left
            while(pre.right is not None and pre.right is not curr):
                pre = pre.right

            if pre.right is None:
                pre.right = curr
                curr = curr.left
            else:
                pre.right = None
                print(curr.data)
                curr = curr.right

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)

morrisTraversal(root)
