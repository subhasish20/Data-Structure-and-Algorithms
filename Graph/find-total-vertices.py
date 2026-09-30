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

    def print_graph(self):
        for vertex in self.graph:
            print(f"{vertex} - > {self.graph[vertex]}")

    def find_total_vertex(self):
        print(f"total number of vertices is {list(self.graph.keys())}")

graph = Graph()

graph.add_edge(1, 2)
graph.add_edge(1, 3)
graph.add_edge(1, 4)
graph.add_edge(2, 5)
graph.add_edge(2, 6)
graph.add_edge(3, 4)
graph.add_edge(4, 6)
graph.add_edge(5, 6)

graph.print_graph()

graph.find_total_vertex()
