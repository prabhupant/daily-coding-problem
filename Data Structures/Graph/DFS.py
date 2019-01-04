from collections import defaultdict

class Graph:

    def __init__(self):
        self.graph = defaultdict(list)

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def DFSUtil(self, v, visited):
        visited[v] = True
        print(v)
        for i in self.graph[v]:
            if visited[i] is False:
                self.DFSUtil(i, visited)

    def DFS(self):
        V = len(self.graph)
        visited = [False]*V
        for i in range(V):
            if visted[i] == False:
                self.DFSUtil(i, visited)

g = Graph()

