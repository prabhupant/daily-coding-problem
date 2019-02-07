class Node(object):
    def __init__(self, data, parent=None, rank=0):
        self.data = data
        self.parent = parent
        self.rank = rank

    def __str__(self):
        return str(self.data)

    def __repr__(self):
        return self.__str__()




class DisjointSet(object):
    def __init__(self):
        self.map = {}

    def make_set(self, data):
        node = Node(data)
        node.parent = node
        self.map[data] = node

    def union(self, data1, data2):
        node1 = self.map[data1]
        node2 = self.map[data2]

        parent1 = self.find_set_util(node1)
        parent2 = self.find_set_util(node2)

        if parent1.data == parent2.data:
            return

        if parent1.rank >= parent2.rank:
            if parent1.rank == parent2.rank:
                parent1.rank += 1
            parent2.parent = parent2
        else:
            parent1.parent = parent2

    def find_set(self, data):
        return self.find_set_util(self.map[data])

    def find_set_util(self, node):
        parent = node.parent
        if parent == node:
            return parent
        node.parent = self.find_set_util(node.parent)
        return node.parent


disjoint_set = DisjointSet()
disjoint_set.make_set(1)
disjoint_set.make_set(2)
disjoint_set.make_set(3)
disjoint_set.make_set(4)
disjoint_set.union(1,2)
disjoint_set.union(3,4)
print(disjoint_set.find_set(1))
print(disjoint_set.find_set(3))
