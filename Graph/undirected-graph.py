class UndirectedGraph:
    # Dictionary stores values like:
    # A -> ['B', 'C']
    # B -> ['A', 'D']
    # C -> ['A', 'D']
    # D -> ['B', 'C']

    def __init__(self):
        self.graph = {}

    def addEdge(self, u, v):
        # Add u if it is not present
        if u not in self.graph:
            self.graph[u] = []

        # Add v if it is not present
        if v not in self.graph:
            self.graph[v] = []

        # Undirected graph: add both directions
        self.graph[u].append(v)
        self.graph[v].append(u)

    def display(self):
        for vertex in self.graph:
            print(vertex, "->", self.graph[vertex])


g = UndirectedGraph()

g.addEdge(1, 2)
g.addEdge(1, 3)
g.addEdge(2, 4)
g.addEdge(3, 4)

g.display()
