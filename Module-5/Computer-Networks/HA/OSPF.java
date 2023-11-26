import java.util.*;

public class OSPF {
    static class Graph {
        private final Map<Integer, Map<Integer, Integer>> adjacencyList;
        private final Map<Integer, Map<Integer, String>> networkAddresses;
        
        public Graph() {
            this.adjacencyList = new HashMap<>();
            this.networkAddresses = new HashMap<>();
        }
        
        public void addEdge(int source, int destination, int weight) {
            adjacencyList.computeIfAbsent(source, k -> new HashMap<>()).put(destination, weight);
            adjacencyList.computeIfAbsent(destination, k -> new HashMap<>()).put(source, weight); // For an undirected graph
        }
        
        public void lsdb() {
            System.out.println("\nLink State Database:");

            for (int router : adjacencyList.keySet()) {
                System.out.print("Router " + router + ": ");
                Map<Integer, Integer> neighbors = adjacencyList.get(router);
                
                for (Map.Entry<Integer, Integer> neighborEntry : neighbors.entrySet()) {
                    System.out.print("(" + neighborEntry.getKey() + ", Cost: " + neighborEntry.getValue() + ") ");
                }
                
                System.out.println();
            }
        }

        public Map<Integer, Integer> dijkstra(int source) {
            Map<Integer, Integer> distances = new HashMap<>();
            Map<Integer, Integer> previousNodes = new HashMap<>();
            PriorityQueue<Node> pq = new PriorityQueue<>(Comparator.comparingInt(n -> n.distance));

            pq.add(new Node(source, 0));
            distances.put(source, 0);

            while (!pq.isEmpty()) {
                Node current = pq.poll();
                int currentNode = current.vertex;
                int currentDistance = current.distance;

                for (Map.Entry<Integer, Integer> neighbor : adjacencyList.getOrDefault(currentNode, Collections.emptyMap()).entrySet()) {
                    int neighborVertex = neighbor.getKey();
                    int newDistance = currentDistance + neighbor.getValue();

                    if (!distances.containsKey(neighborVertex) || newDistance < distances.get(neighborVertex)) {
                        distances.put(neighborVertex, newDistance);
                        previousNodes.put(neighborVertex, currentNode);
                        pq.add(new Node(neighborVertex, newDistance));
                    }
                }
            }

            return previousNodes;
        }

        public void disp_net() {
            // Display stored network addresses
            System.out.println("\nStored Network Addresses:");
            for (Map.Entry<Integer, Map<Integer, String>> entry : networkAddresses.entrySet()) {
                int router = entry.getKey();
                Map<Integer, String> addresses = entry.getValue();
                for (Map.Entry<Integer, String> addressEntry : addresses.entrySet()) {
                    int neighbor = addressEntry.getKey();
                    String networkAddress = addressEntry.getValue();
                    System.out.println("Between Router " + router + " and Router " + neighbor + ": " + networkAddress);
                }
            }
        }

        public void sendSpecialHelloPackets(int routerId) {
            System.out.println("Sending Special Hello Packets from Router " + routerId + "...");

            List<Integer> neighbors = new ArrayList<>(adjacencyList.get(routerId).keySet());
            for (int neighbor : neighbors) {
                System.out.println("  Sending Special Hello to Router " + neighbor);
//                try {
//                    Thread.sleep(10000); // 10 seconds delay
//                } catch (InterruptedException e) {
//                    e.printStackTrace();
//                }
                receiveSpecialHelloPacket(routerId, neighbor);
            }
        }

        private void receiveSpecialHelloPacket(int sourceRouter, int destinationRouter) {
            System.out.println("    Received Special Hello Packet from Router " + sourceRouter + " to Router " + destinationRouter);

            // Placeholder logic to simulate obtaining information about the network address
            // For simplicity, let's assume a predefined network address for each router pair
            String networkAddress = getNetworkAddress(sourceRouter, destinationRouter);

            // Display the obtained network address
            System.out.println("    Obtained Network Address: " + networkAddress);

            // Store the network address in the data structure
            networkAddresses.computeIfAbsent(sourceRouter, k -> new HashMap<>()).put(destinationRouter, networkAddress);
            networkAddresses.computeIfAbsent(destinationRouter, k -> new HashMap<>()).put(sourceRouter, networkAddress);
        }

        // Placeholder method to simulate obtaining the network address based on router pairs
        private String getNetworkAddress(int router1, int router2) {
            // In a real scenario, you would have a more sophisticated logic to obtain the network address.
            // For simplicity, let's assume a simple format where the network address is "192.168.1.x" for each router pair.
            return "192.168.1." + router1 + "-" + router2;
        }

        public void simulateOSPF() {

            // Display adjacency list and link state packets
            for (int router : adjacencyList.keySet()) {
                System.out.println("Router " + router + ":");
                List<Integer> neighbors = new ArrayList<>(adjacencyList.get(router).keySet());
                System.out.println("  Neighbors: " + neighbors);
                System.out.println("  Link State Packet for the Router: " + adjacencyList.get(router));
            }
        }


        public List<Integer> getShortestPath(int source, int destination) {
            Map<Integer, Integer> previousNodes = dijkstra(source);
            List<Integer> path = new ArrayList<>();

            int current = destination;
            while (previousNodes.containsKey(current)) {
                path.add(current);
                current = previousNodes.get(current);
            }

            path.add(source);
            Collections.reverse(path);
            return path;
        }

        public void printRoutingTable(int routerId) {
            System.out.println("\nRouting Table for Router " + routerId + ":");

            // Get the shortest path information using Dijkstra's algorithm
            Map<Integer, Integer> previousNodes = dijkstra(routerId);

            // Display the routing table
            System.out.printf("%-20s %-10s %-15s\n", "Network Address", "Cost", "Next Hop");
            System.out.println("-------------------------------------------------------");

            for (int destinationRouter : previousNodes.keySet()) {
                if (destinationRouter != routerId) {
                    // Get the network address
                    String networkAddress = networkAddresses.get(routerId).get(destinationRouter);

                    // Check if network address is null
                    if (networkAddress != null) {
                        // Get the cost
                        int cost = adjacencyList.get(routerId).get(destinationRouter);

                        // Get the next hop (neighboring router)
                        int nextHop = destinationRouter;

                        // Display the routing table entry
                        System.out.printf("%-20s %-10d %-15s\n", networkAddress, cost, "Router " + nextHop);
                    }
                }
            }
        }

        private static class Node {
            private final int vertex;
            private final int distance;

            public Node(int vertex, int distance) {
                this.vertex = vertex;
                this.distance = distance;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of routers: ");
        int numRouters = scanner.nextInt();

        Graph graph = new Graph();

        for (int i = 0; i < numRouters; i++) {
            System.out.print("Enter the number of neighbors for Router " + (i + 1) + ": ");
            int numNeighbors = scanner.nextInt();

            for (int j = 0; j < numNeighbors; j++) {
                System.out.print("Enter neighbor router ID for Router " + (i + 1) + ": ");
                int neighborId = scanner.nextInt();
                System.out.print("Enter the cost to neighbor: ");
                int cost = scanner.nextInt();

                graph.addEdge(i + 1, neighborId, cost);
            }
        }

        System.out.print("Enter the source router: ");
        int sourceRouter = scanner.nextInt();

        System.out.print("Enter the destination router: ");
        int destinationRouter = scanner.nextInt();

        // After taking input for the network topology, simulate OSPF operations
        for (int i = 1; i <= numRouters; i++) {
            graph.sendSpecialHelloPackets(i);
        }

        System.out.println("\nLink State Packets for Routers:");
        graph.simulateOSPF();
        
        graph.lsdb();

        List<Integer> shortestPath = graph.getShortestPath(sourceRouter, destinationRouter);

        System.out.println("\nShortest Path from Router " + sourceRouter + " to Router " + destinationRouter + ":");
        System.out.println("  Path: " + shortestPath);

        int cost = 0;
        for (int i = 0; i < shortestPath.size() - 1; i++) {
            int currentRouter = shortestPath.get(i);
            int nextRouter = shortestPath.get(i + 1);
            cost += graph.adjacencyList.get(currentRouter).get(nextRouter);
        }
        System.out.println("  Cost: " + cost);
        
     // Take input for the router to print the routing table
        System.out.print("\nEnter the router ID to print the routing table: ");
        int routerToPrint = scanner.nextInt();

        // Print the routing table for the specified router
        graph.printRoutingTable(routerToPrint);
        
        scanner.close();
    }
}
