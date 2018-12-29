class Node:

    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def diagonalPrintUtil(root, d, diagonal_map):
    if root is None:
        return

    try:
        diagonal_map[d].append(root.data)
    except KeyError:
        diagonal_map[d] = [root.data]

    diagonalPrintUtil(root.left, d+1, diagonal_map)
    diagonalPrintUtil(root.right, d, diagonal_map)

def diagonalPrint(root):

    diagonal_map = dict()
    diagonalPrintUtil(root, 0, diagonal_map)
    print("Diagonal traversal is : ")
    for i in diagonal_map:
        for j in diagonal_map[i]:
            print(j)
        print " "

root = Node(8)

diagonalPrint(root)
