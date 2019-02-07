class Node:

    def __init__(self, data, parent=None, rank=0):
        self.data = data
        self.parent = parent
        self.rank = rank

    def __str__(self):
        return str(self.data)

    def __repr__(self):
        return self.__str__()

class DisjointSet:

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

        if parent1.data == parent1.data:
            return

        if parent1.rank >= parent2.rank:
            if parent1.rank == parent2.rank:
                parent1.rank += 1
            parent2.parent = parent1
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


def get_key(edge):
    return edge.weight

def minimum_spannin_tree(graph):
    disjoint_set = DisjointSet()
    sorted_edges = sorted(graph.all_edges, key = get_key)
    print(sorted_edges)

    for vertex in graph.all_vertex.values():
        disjoint_set.make_set(vertex.id)

    result_edge = []

    for edge in sorted_edges:
        root1 = disjoint_set.find_set(edge.vertex1.id)
        root2 = disjoint_set.find_set(edge.vertex2.id)

        if root1 == root2:
            continue
        else:
            result_edge.append(edge)
            disjoint_set.union(edge.vertex1.id, edge.vertex2.id)

    return result_edge

if __name__ == '__main__':
    graph = Graph(False)
    graph.add_edge(1,3,1)
    graph.add_edge(1,2,4)
    graph.add_edge(2,4,2)
    graph.add_edge(2,5,1)
    graph.add_edge(2,6,3)
    graph.add_edge(3,4,5)
    graph.add_edge(3,7,8)
    graph.add_edge(4,7,2)
    graph.add_edge(6,5,2)
    graph.add_edge(6,4,3)

    result = minimum_spanning_tree(graph)
    for edge in result:
        print(edge)

