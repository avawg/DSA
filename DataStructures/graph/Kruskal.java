import java.util.*;

public class Kruskal {

    static class Edge {
        int from, to, cost;

        public Edge(int from, int to, int cost) {
            this.from = from;
            this.to = to;
            this.cost = cost;
        }
    }

    // 找集合根节点
    static int find(int parents[], int x) {
        if (parents[x] == -1) // 根
            return x;
        else
            return parents[x] = find(parents, parents[x]); // 路径压缩
    }

    // 最小生成树算法 时间复杂度 O(|E|log|E|)
    static int kruskal(List<Edge> edges, int n) {
        int[] parents = new int[n + 1];
        for (int i = 1; i <= n; i++)
            parents[i] = -1;
        // 自定义排序规则，由小到大排序
        Queue<Edge> queue = new PriorityQueue<>((e1, e2) -> e1.cost - e2.cost);
        for (Kruskal.Edge edge : edges) {
            queue.add(edge);
        }

        int cnt = 0, cost = 0;
        // 每次取权值最小的边log(|E|)，直到取n-1条边 < |E|log|E|
        while (cnt < n && !queue.isEmpty()) {
            Edge edge = queue.remove();
            int x = find(parents, edge.from);
            int y = find(parents, edge.to);
            if (x != y) { // 合并
                parents[x] = y;
                cost += edge.cost;
                cnt++;
            }
            if (cnt == n - 1) return cost;
        }
        return -1;
    }

    public static void main(String[] args) {
        int n, m; // n节点数，m边数
        Scanner scanner = new Scanner(System.in);
        m = scanner.nextInt();
        n = scanner.nextInt();
        List<Edge> edges = new ArrayList<>(m);
        for (int i = 0; i < m; i++) {
            int from = scanner.nextInt();
            int to = scanner.nextInt();
            int cost = scanner.nextInt();
            edges.add(new Edge(from, to, cost));
        }
        int cost = kruskal(edges, n);
        if (cost != -1) {
            System.out.println(cost);
        } else {
            System.out.println("?");
        }
    }
}