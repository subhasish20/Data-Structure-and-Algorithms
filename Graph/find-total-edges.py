
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
        vertices = []
        for vertex in self.graph:
            if self.graph[vertex] not in vertices:
                vertices.extend([vertex])
        print(f"total number of vertices are {len(vertices)}")

    def find_total_edges(self):
        edges = 0
        for vertex in self.graph:
            edges += len(self.graph[vertex])
        # all value will come double so // 2 wll gie the total edges
        # For example:
        # 1 -- 2
        # is stored as:
            # 1: [2]
            # 2: [1]
        # So we count all connections first, then divide by 2.
        # 3 + 3 + 2 + 3 + 2 + 3 = 16
        # 16 // 2 = 8 edges
        total_edges = edges // 2
        print(f"The total number of edges is {total_edges}")


    """
    for directed graph the code will be
    def find_total_edges(self):
        total_edges = 0

        for vertex in self.graph:
            total_edges += len(self.graph[vertex])

        print(f"total number of edges are {total_edges}")

    """

g = Graph()


g.add_edge(1, 2)
g.add_edge(1, 3)
g.add_edge(1, 4)
g.add_edge(2, 5)
g.add_edge(2, 6)
g.add_edge(3, 4)
g.add_edge(4, 6)
g.add_edge(5, 6)



g.print_graph()

g.find_total_vertex()

g.find_total_edges()
