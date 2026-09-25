graph = {} # declare a dictionary to store the E,V

def add_edge(v,u):
    if u not in graph:
        graph[u] = []

    graph[u].append(v)


# Create the same graph
add_edge(0, 1)
add_edge(1, 2)
add_edge(1, 3)
add_edge(2, 3)
add_edge(2, 4)

# Print graph
for node in sorted(graph.keys()):
    print(f"{node}-> {' '.join(map(str, graph[node]))}")
