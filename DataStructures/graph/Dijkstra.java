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
    public Edge(int id, int dist) {
        this.id = id;
        this.dist = dist;
    }
}

public class Dijkstra {

    static void dijkstra(List<List<Node>> G, int s, int t) {
        int n = G.size();
        int[] minDist = new int[n];
        boolean[] visited = new boolean[n];
        int[] path = new int[n];
        for (int i = 0; i < n; i++) {
            minDist[i] = Integer.MAX_VALUE;
            path[i] = -1;
        }

        MinHeap<Node> queue = new MinHeap<>(n);

        // 将源节点加入
        dist[s] = 0;
        visited[s] = true;
        for (Edge edge : G.get(s)) {
            queue.add(new Node(edge.to, edge.dist));
        }

        // 按递增的顺序找出到各顶点的最短路
        /** 时间复杂度 用数组记录最小值 O(|V||V| + |E|) = O(|V||V|)
                      用 min-heap O(|V|log(|V|) + |E|log(|V|) = O(|E|log(|V|))
                      用 Fibonacci heap O(|V|log(|V|) + |E|)
         */

        // 每次找到与s距离最近的节点u
        while (!queue.isEmpty()) {
            Node u = queue.remove();
            // 根据u更新其邻接点到s的距离
            for (Edge edge : G.get(u.id)) {
                if (visited[edge.to])
                    continue;
                if (dist[u.id] + edge.dist < dist[edge.to]) {
                    dist[edge.to] = dist[u.id] + edge.dist;
                    path[edge.to] = u.id; // 更新路径
                    queue.decrease(edge.to, dist[edge.to]);
                }
            }
        }
        while (t != -1) {
            System.out.println(path[t] + ' ');
            t = path[t];
        }
    }

    public static void main(String[] args) {

        int n, m; // n节点数，m边数
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        // 初始化图，邻接表存储
        List<List<Edge>> G = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            G.add(new ArrayList<>());
        }
        // 读入数据
        for (int i = 0; i < m; i++) {
            int s = scanner.nextInt();
            int t = scanner.nextInt();
            int dist = scanner.nextInt();
            G.get(s).add(new Edge(t, dist));
            G.get(t).add(new Edge(s, dist));
        }
        int s, t;
        s = scanner.nextInt();
        t = scanner.nextInt();
        dijkstra(G, s, t);
    }
}