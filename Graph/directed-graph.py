class DirectedGraph:
    # the dictionary will store the value like :
        #  A -> ['B', 'C']
        #  B -> ['A', 'D']
        #  C -> ['A', 'D']
        #  D -> ['B', 'C']
    def __init__(self):
        self.graph = {}

    def addEdge(self, u, v):
        # if the Vertex is not present add it in the dict
        if v not in self.graph:
            self.graph[v] = []

        self.graph[v].append(u) # add the Edges to the V1->V2

    def display(self):
        for vertex in self.graph:
            print(vertex, "->", self.graph[vertex])


g = DirectedGraph()

g.addEdge(1,2)
g.display()
