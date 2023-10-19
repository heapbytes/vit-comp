import heapq

class Router:
    def __init__(self, router_id):
        self.router_id = router_id
        self.neighbors = {}

    def add_neighbor(self, neighbor, cost):
        self.neighbors[neighbor] = cost


class OSPF:
    def __init__(self):
        self.routers = {}

    def add_router(self, router_id):
        if router_id not in self.routers:
            self.routers[router_id] = Router(router_id)

    def add_link(self, router1_id, router2_id, cost):
        self.routers[router1_id].add_neighbor(router2_id, cost)
        self.routers[router2_id].add_neighbor(router1_id, cost)

    def dijkstra(self, source):
        distances = {router_id: float('inf') for router_id in self.routers}
        distances[source] = 0
        pq = [(0, source)]

        while pq:
            current_distance, current_router = heapq.heappop(pq)

            if current_distance > distances[current_router]:
                continue

            for neighbor, cost in self.routers[current_router].neighbors.items():
                distance = current_distance + cost

                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    heapq.heappush(pq, (distance, neighbor))

        return distances

    def find_shortest_path(self, source, destination):
        distances = self.dijkstra(source)
        shortest_path = []
        current_router = destination

        while current_router != source:
            shortest_path.append(current_router)
            current_router = min(self.routers[current_router].neighbors, key=lambda x: distances[x])

        shortest_path.append(source)
        shortest_path.reverse()
        return shortest_path

    def print_shortest_path(self, source, destination):
        shortest_path = self.find_shortest_path(source, destination)
        print(f"Shortest path from Router {source} to Router {destination}: {' -> '.join(map(str, shortest_path))}")


# Creating OSPF instance and adding routers and links
ospf = OSPF()

# Adding routers
for i in range(1, 10):
    ospf.add_router(i)

# Creating the square topology
for i in range(1, 4):
    ospf.add_link(i, i + 1, 1)
    ospf.add_link(i, i + 3, 1)
ospf.add_link(1, 4, 1)  # Closing the square
ospf.add_link(4, 7, 1)  # Closing the square

# Adding the central router and connecting it to the square
ospf.add_link(5, 2, 1)
ospf.add_link(5, 8, 1)
ospf.add_link(5, 4, 1)
ospf.add_link(5, 6, 1)

# Taking user input for source and destination routers
source_router = int(input("Enter source router (1-9): "))
destination_router = int(input("Enter destination router (1-9): "))

# Validating user input
if source_router in ospf.routers and destination_router in ospf.routers:
    ospf.print_shortest_path(source_router, destination_router)
else:
    print("Invalid source or destination router ID.")

