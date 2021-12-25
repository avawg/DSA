/*
	kahn 拓扑排序
	给出一个图的结构，输出其拓扑排序序列，要求在同等情况下，编号小的顶点在前面
	输出若干行整数，第一行有两个数，分别为顶点数V和边数a
	接下来有a行，每一行有两个数，分别是这条边的两个顶点
*/

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Kahn {

    static List<Integer> kahn(List<List<Integer>> g) {
		// 求拓扑序列
        int n = g.size();
        int[] in_degree = new int[n]; // 记录入度
        for (List<Integer> adj : g) {
            for (int node : adj) {
                in_degree[node]++;
            }
        }

        // 用优先及队列存储入度为0的顶点，编号小的顶点在前
        // 时间复杂度O(|V| + |E|)，不要求编号小顶点在前
        PriorityQueue<Integer> q = new PriorityQueue<>();
        List<Integer> ret = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            if (in_degree[i] == 0)
                q.add(i);
        }
        while (!q.isEmpty()) {
            int x = q.remove(); // 选择入度为0的顶点出队
            ret.add(x);
            // 将其指向的顶点入度减1，若为0则入队
            List<Integer> adj = g.get(x);
            for (int node : adj) {
                if (--in_degree[node] == 0) {
                    q.add(node);
                };
            }
        }
        return ret;
    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner scanner = new Scanner(System.in);
        int n, m;
        n = scanner.nextInt();
        m = scanner.nextInt();

        List<List<Integer>> g = new ArrayList<>(); // 邻接表记录图
        for (int i = 0; i < n; i++) {
            g.add(new ArrayList<>());
        }

        int a, b;
        for (int i = 0; i < m; ++i) {
            a = scanner.nextInt();
            b = scanner.nextInt();
            g.get(a).add(b);
        }
        List<Integer> seq = kahn(g);
        System.out.println(seq);
        scanner.close();
    }
}