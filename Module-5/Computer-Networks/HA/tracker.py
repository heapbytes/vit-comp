import heapq

class Graph:
    def __init__(self):
        self.nodes = set()
        self.edges = {}

    def add_node(self, value):
        self.nodes.add(value)
        self.edges[value] = []

    def add_edge(self, from_node, to_node, weight):
        self.edges[from_node].append((to_node, weight))
        self.edges[to_node].append((from_node, weight))

    def dijkstra(self, start):
        priority_queue = [(0, start)]
        visited = set()
        distances = {node: float('infinity') for node in self.nodes}
        distances[start] = 0

        while priority_queue:
            current_distance, current_node = heapq.heappop(priority_queue)

            if current_node not in visited:
                visited.add(current_node)

                for neighbor, weight in self.edges[current_node]:
                    distance = current_distance + weight

                    if distance < distances[neighbor]:
                        distances[neighbor] = distance
                        heapq.heappush(priority_queue, (distance, neighbor))

        return distances

# Create a sample network with 10 routers
network = Graph()
for i in range(1, 11):
    network.add_node(f'Router{i}')

# Add connections between routers with weights
network.add_edge('Router1', 'Router2', 3)
network.add_edge('Router1', 'Router3', 2)
network.add_edge('Router2', 'Router4', 1)
network.add_edge('Router2', 'Router5', 4)
network.add_edge('Router3', 'Router6', 5)
network.add_edge('Router3', 'Router7', 6)
network.add_edge('Router4', 'Router8', 2)
network.add_edge('Router5', 'Router8', 3)
network.add_edge('Router6', 'Router9', 4)
network.add_edge('Router7', 'Router10', 5)
network.add_edge('Router8', 'Router10', 2)
network.add_edge('Router9', 'Router10', 3)

# Take user input for source and destination routers
source_router = input("Enter source router (Router1 to Router10): ")
destination_router = input("Enter destination router (Router1 to Router10): ")

# Calculate shortest path using Dijkstra's algorithm
distances = network.dijkstra(source_router)

# Print the shortest path from source to destination
shortest_path = []
current_node = destination_router
while current_node != source_router:
    shortest_path.append(current_node)
    neighbors = network.edges[current_node]
    for neighbor, weight in neighbors:
        if distances[current_node] == distances[neighbor] + weight:
            current_node = neighbor
            break

shortest_path.append(source_router)
shortest_path.reverse()

print(f"Shortest path from {source_router} to {destination_router}: {' -> '.join(shortest_path)}")

