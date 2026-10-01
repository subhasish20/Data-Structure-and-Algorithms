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

    def bfs(self, start_vertex):
        if start_vertex not in self.graph:
            return []

        visited_node = set() # used to keep track of nodes that have already been visited

        bfs_traversal = [] # used to store the bfs

        queue = [start_vertex] # store the values to be explore

        visited_node.add(start_vertex) # we took the start vertex and stoe the in set which will no be visited again
        while queue:
            current = queue.pop(0)
            bfs_traversal.append(current)
            for neighbour_node in self.graph[current]:
                if neighbour_node not in visited_node:
                    visited_node.add(neighbour_node)
                    queue.append(neighbour_node)
        return bfs_traversal

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

print(f"BFS {g.bfs(3)}")
