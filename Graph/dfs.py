class Graph:
    def __init__(self):
        self.graph = {}

    def add_edge(self, u, v):
        if u not in self.graph:
            self.graph[u] = []

        if v not in self.graph:
            self.graph[v] = []

        self.graph[u].append(v)
        self.graph[v].append(u)


    def display_graph(self):
        for vertex in self.graph:
            print(f"{vertex} - > {self.graph[vertex]}")

    def dfs(self, start_vertex):
        pass



g = Graph()

g.add_edge(1, 2)
g.add_edge(1, 3)
g.add_edge(1, 4)
g.add_edge(2, 5)
g.add_edge(2, 6)
g.add_edge(3, 4)
g.add_edge(4, 6)
g.add_edge(5, 6)

g.display_graph()

print(f"BFS {g.dfs(3)}")
