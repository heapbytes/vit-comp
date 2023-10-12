import java.util.*;

public class Dijkstra {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of vertices and edges (in the same order) - ");
        int vertices = sc.nextInt();
        int edges = sc.nextInt();

        ArrayList<ArrayList<Integer>> vec = new ArrayList<>();

        for (int i = 0; i < edges; i++) {
            System.out.print("Enter src node, destination node and weight - ");
            int u = sc.nextInt() - 1; 
            int v = sc.nextInt() - 1; 
            int w = sc.nextInt();

            ArrayList<Integer> temp = new ArrayList<>();
            temp.add(u);
            temp.add(v);
            temp.add(w);

            vec.add(temp);
        }
        System.out.println("Graph is - ");
        System.out.println(vec);
        System.out.print("Enter source node - ");
        int source = sc.nextInt() - 1; // Adjust for 0-based indexing
        System.out.println("Shortest paths are - ");
        ArrayList<Integer> shortestPaths = dijkstra(vec, vertices, edges, source);
        System.out.println(Arrays.toString(shortestPaths.toArray()));
        sc.close();
    }

    public static ArrayList<Integer> dijkstra(ArrayList<ArrayList<Integer>> vec, int vertices, int edges, int source) {
        ArrayList<ArrayList<Pair>> graph = new ArrayList<>();
        for (int i = 0; i < vertices; i++)
            graph.add(new ArrayList<>());

        for (ArrayList<Integer> edge : vec) {
            graph.get(edge.get(0)).add(new Pair(edge.get(1), edge.get(2)));
            graph.get(edge.get(1)).add(new Pair(edge.get(0), edge.get(2)));
        }

        PriorityQueue<Pair> pq = new PriorityQueue<>((x, y) -> x.dist - y.dist);

        int[] vis = new int[vertices];
        int[] parents = new int[vertices];

        for (int i = 0; i < vis.length; i++) {
            if (i == source) {
                vis[i] = 0;  // Set the source vertex distance to 0
            } else {
                vis[i] = Integer.MAX_VALUE;
            }
        }

        pq.add(new Pair(source, 0));

        while (!pq.isEmpty()) {
            Pair curr = pq.poll();

            int currD = curr.dist;
            int node = curr.node;

            ArrayList<Pair> children = graph.get(node);
            for (Pair p : children) {
                int newD = currD + p.dist;
                if (newD < vis[p.node]) {
                    vis[p.node] = newD;
                    parents[p.node] = node;
                    pq.add(new Pair(p.node, newD));
                }
            }
        }
        ArrayList<Integer> ans = new ArrayList<>();
        for (int index = 0; index < vis.length; index++) {
            ans.add(vis[index]);
        }
        System.out.print("Parents of each node - ");
        System.out.println(Arrays.toString(parents));
        return ans;
    }
}

class Pair {
    int dist, node;

    Pair(int _node, int _dist) {
        node = _node;
        dist = _dist;
    }

    @Override
    public String toString() {
        return node + " - " + dist;
    }

    @Override
    public boolean equals(Object obj) {
        Pair p = (Pair) obj;
        return this.node == p.node;
    }
}

