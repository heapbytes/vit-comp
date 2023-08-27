import java.util.*;

public class BFSPROG {

    static class Graph {
        int vertices;
        LinkedList<Integer>[] adjacencyList;

        Graph(int vertices) {
            this.vertices = vertices;
            adjacencyList = new LinkedList[vertices];

            for (int i = 0; i < vertices; i++) {
                adjacencyList[i] = new LinkedList<>();
            }
        }

        void addEdge(int source, int destination) {
            adjacencyList[source].add(destination);
        }

        void BFSTraversal(int startNode) {
            Queue<Integer> resultQueue = new LinkedList<>();
            boolean[] visited = new boolean[vertices];

            resultQueue.add(startNode);
            visited[startNode] = true;

            while (!resultQueue.isEmpty()) {
                int currentNode = resultQueue.poll();
                System.out.print(currentNode + " ");

                for (int neighbor : adjacencyList[currentNode]) {
                    if (!visited[neighbor]) {
                        resultQueue.add(neighbor);
                        visited[neighbor] = true;
                    }
                }
            }
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of vertices in the graph: ");
        int numVertices = sc.nextInt();

        Graph g = new Graph(numVertices);

        System.out.print("Enter the number of edges: ");
        int numEdges = sc.nextInt();

        for (int i = 0; i < numEdges; i++) {
            System.out.print("Enter source and destination for edge " + (i + 1) + ": ");
            int source = sc.nextInt();
            int destination = sc.nextInt();
            g.addEdge(source, destination);
        }

        System.out.print("Enter the starting node for BFS: ");
        int startNode = sc.nextInt();

        System.out.println("BFS traversal is as follows: ");
        g.BFSTraversal(startNode);
    }
}
