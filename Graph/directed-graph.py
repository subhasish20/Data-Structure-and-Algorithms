class DirectedGraph:

    def __init__(self):
        self.graph = {}

    # u is the source and v is the destination
    def addEdge(self, u, v):
        if u not in self.graph:
            # creating a empty vertex if not present
            self.graph[u] = []

        #  connecting with  vertex
        self.graph[u].append(v)

    def printGraph(self):
        for vertex in self.graph:
            print(f"{vertex} -> {self.graph[vertex]}")


graph = DirectedGraph()

graph.addEdge(1,2)
graph.addEdge(2,5)
graph.addEdge(2,6)
graph.addEdge(3,1)
graph.addEdge(4,1)
graph.addEdge(4,3)
graph.addEdge(5,6)
graph.addEdge(6,4)


graph.printGraph()
