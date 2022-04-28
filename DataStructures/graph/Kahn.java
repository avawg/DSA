/**
 *	kahn 拓扑排序
 *	给出一个图的结构，输出其拓扑排序序列，要求在同等情况下，编号小的顶点在前面
 *	输出若干行整数，第一行有两个数，分别为顶点数V和边数a
 *	接下来有a行，每一行有两个数，分别是这条边的两个顶点
*/

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Kahn {

    static List<Integer> kahn(List<Integer>[] graph) {
		// 求拓扑序列
        int n = graph.length;
        int[] inDegree = new int[n]; // 记录入度
        for (List<Integer> adj : graph) {
            for (int node : adj) {
                inDegree[node]++;
            }
        }

        // 用优先及队列存储入度为0的顶点，编号小的顶点在前
        // 时间复杂度O(|V| + |E|)，不要求编号小顶点在前
        PriorityQueue<Integer> que = new PriorityQueue<>();
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0)
                que.offer(i);
        }
        while (!que.isEmpty()) {
            int u = que.poll(); // 选择入度为0的顶点出队
            ans.add(u);
            // 将其指向的顶点入度减1，若为0则入队
            List<Integer> adj = graph[u];
            for (int node : adj) {
                if (--inDegree[node] == 0) {
                    que.offer(node);
                };
            }
        }
        return ans;
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        List<Integer>[] g = new List[n]; // 邻接表记录图
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<Integer>();
        }

        int a, b;
        for (int i = 0; i < m; ++i) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            g[a].add(b);
        }
        List<Integer> seq = kahn(g);
        System.out.println(seq);
        scanner.close();
    }
}
