import java.util.*;

// 定义节点
class Edge {
    int to, dist;
    public Edge(int to, int dist) {
        this.to = to;
        this.dist = dist;
    }
}

class Node {
    int id, dist;
    public Node(int id, int dist) {
        this.id = id;
        this.dist = dist;
    }
}

public class Dijkstra {

    static void dijkstra(List<Edge>[] graph, int s, int t) {
        int n = graph.length;
        int[] dist = new int[n];
        boolean[] visited = new boolean[n];
        int[] path = new int[n];
        for (int i = 0; i < n; i++) {
            dist[i] = Integer.MAX_VALUE;
            path[i] = -1;
        }
        PriorityQueue<Node> pq = new PriorityQueue<>();
        // 将源节点加入
        dist[s] = 0;
        visited[s] = true;
        for (Edge edge : graph[s]) {
            int v = edge.to, d = edge.dist;
            dist[v] = d;
            pq.offer(new Node(v, d));
        }

        // 按递增的顺序找出到各顶点的最短路
        /** 时间复杂度 用数组记录最小值 O(|V||V| + |E|) = O(|V||V|)
                      用 min-heap O(|V|log(|V|) + |E|log(|V|) = O(|E|log(|V|))
                      用 Fibonacci heap O(|V|log(|V|) + |E|)
         */

        // 每次找到与s距离最近的节点u
        while (!pq.isEmpty()) {
            Node node = pq.poll();
            int u = node.id;
            // 根据u更新其邻接点到s的距离
            for (Edge edge : graph[u]) {
                int v = edge.to, d = edge.dist;
                if (visited[v])
                    continue;
                if (dist[u] + d < dist[v]) {
                    dist[v] = dist[u] + d;
                    path[v] = u; // 更新路径
                    pq.offer(new Node(v, dist[v]));
                }
            }
        }
        while (t != -1) {
            System.out.println(path[t] + ' ');
            t = path[t];
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // n节点数
        int m = scanner.nextInt(); // m边数
        // 初始化图，邻接表存储
        List<Edge>[] graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        // 读入数据
        for (int i = 0; i < m; i++) {
            int s = scanner.nextInt();
            int t = scanner.nextInt();
            int dist = scanner.nextInt();
            graph[s].add(new Edge(t, dist));
            graph[t].add(new Edge(s, dist));
        }
        int s = scanner.nextInt();
        int t = scanner.nextInt();
        dijkstra(graph, s, t);
    }
}