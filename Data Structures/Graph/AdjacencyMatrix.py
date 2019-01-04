class Graph:

    def __init__(self, num_vertex):
        self.num_vertex = num_vertex
        self.adj_matrix = [[-1] * num_vertex for x in range(num_vertex)]
        self.vertices = {}
        self.vertices_list = [0] * num_vertex

    def set_vertex(self, vtx, id_):
        if 0 <= vtx <= self.num_vertex:
            self.vertices[id_] = vtx
            self.vertices_list[vtx] = id_

    def set_edge(self, from_, to, cost = 0):
        from_ = self.vertices[from_]
        to = self.vertices[to]
        self.adj_matrix[from_][to] = cost
        self.adj_matrix[to][from_] = cost #only for undirected graphs

    def get_vertex(self):
        return self.vertices_list

    def get_edges(self):
        edges = []
        for i in range(self.num_vertex):
            for j in range(self.num_vertex):
                if(self.adj_matrix[i][j] != -1):
                    edges.append((self.vertices_list[i], self.vertices_list[j], self.adj_matrix[i][j]))
        return edges

    def get_matrix(self):
        return self.adj_matrix

