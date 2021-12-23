import java.util.*;

// 定义节点
class Node {
    int id, dist;
    public Node(int id, int dist) {
        this.id = id;
        this.dist = dist;
    }
}

public class Dijkstra {

    static void dijkstra(List<List<Node>> G, int source, int destination) {
        int n = G.size();
        int[] dist = new int[n + 1];
        boolean[] visit = new boolean[n + 1];
        int[] path = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            dist[i] = Integer.MAX_VALUE;
            visit[i] = false;
            path[i] = -1;
        }

        MinHeap queue = new MinHeap(n);

        // 将源节点加入
        dist[source] = 0;
        visit[source] = true;
        for (Node node : G.get(source)) {
            path[node.id] = source;
            queue.add(node.id, node.dist);
        }

        // 按递增的顺序找出到各顶点的最短路
        /** 时间复杂度 用数组记录最小值 O(|V||V| + |E|) = O(|V||V|)
                      用 min-heap O(|V|log(|V|) + |E|log(|V|) = O(|E|log(|V|))
                      用 Fibonacci heap O(|V|log(|V|) + |E|)
         */
        while (!queue.isEmpty()) {
            Node minDistNode = queue.remove();
            // 更新邻接点到u的最小距离
            for (Node node : G.get(minDistNode.id)) {
                if (visit[node.id])
                    continue;
                if (dist[minDistNode.id] + node.dist < dist[node.id]) {
                    dist[node.id] = dist[minDistNode.id] + node.dist;
                    path[node.id] = minDistNode.id; // 更新路径
                    queue.decrease(node.id, dist[node.id]);
                }
            }
        }

        // 输出最短路径距离 和 到destination路径
        for (int i = 1; i <= n; i++) {
            System.out.print(dist[i] + ' ');
        }
        System.out.println();
        while (destination != -1) {
            System.out.println(path[destination] + ' ');
            destination = path[destination];
        }
    }

    public static void main(String[] args) {

        int n, m; // n节点数，m边数
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        // 初始化图，邻接表存储
        List<List<Node>> G = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            G.add(new ArrayList<>());
        }
        // 读入数据
        for (int i = 0; i < m; i++) {
            int s = scanner.nextInt();
            int t = scanner.nextInt();
            int dist = scanner.nextInt();
            G.get(s).add(new Node(t, dist));
            G.get(t).add(new Node(s, dist));
        }
        int source, destination;
        source = scanner.nextInt();
        destination = scanner.nextInt();
        dijkstra(G, source, destination);
    }
}