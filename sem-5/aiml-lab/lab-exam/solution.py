nodes = int(input("Enter number of nodes: "))
print("Nodes are called: ")

graph = []

for i in range(nodes):
    temp = []
    for j in range(nodes):
        temp.append(0)
    graph.append(temp)
    print(i, end=" ")
print()

for i in range(nodes):
    neighbors = input(f"node {i} is connected to: ")
    nums = []
    if len(neighbors) > 1:
        nums = [int(x) for x in neighbors.split(" ")]
    else:
        nums = [int(neighbors)]
    for j in nums:
        graph[i][j] = 1
        graph[j][i] = 1

def is_allowed(graph, colors, node, color):
    for i in range(len(graph)):
        if graph[node][i] == 1 and colors[i] == color:
            return False
    return True

def solve(graph, node, colors):
    nodes = len(graph)

    if node >= nodes:
        return True

    for color in range(1, 5):
        if is_allowed(graph, colors, node, color):
            colors[node] = color
            if solve(graph, node + 1, colors):
                return True
            colors[node] = 0

    return False

print("Final Adjacency Matrix: ")

for i in range(len(graph)):
    print(i, graph[i])

colors = [0] * len(graph)

color_map = {
    1: "Red",
    2: "Blue",
    3: "Green",
    4: "Yellow"
}

if solve(graph, 0, colors):
    for i in range(len(colors)):
        print(f"Node {i} has {color_map[colors[i]]} color")
else:
    print("No Solution Found")

