class UndirectedGraph:

    def __init__(self):
        self.graph = {}

    def addEdge(self, u, v):
        if u not in self.graph:
            self.graph[u] = []
        if v not in self.graph:
            self.graph[v] = []

        self.graph[u].append(v)
        self.graph[v].append(u)

    def printGraph(self):
        for vertex in self.graph:
            print(f"{vertex} -> {self.graph[vertex]}")



graph = UndirectedGraph()


graph.addEdge(1, 2)
graph.addEdge(1, 3)
graph.addEdge(1, 4)
graph.addEdge(2, 5)
graph.addEdge(2, 6)
graph.addEdge(3, 4)
graph.addEdge(4, 6)
graph.addEdge(5, 6)


graph.printGraph()
