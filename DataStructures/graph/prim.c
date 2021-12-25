#include <stdio.h>

const int MAX_NUM = 110;

int prim(int G[][MAX_NUM], int n);

int main() {
    int n, m; // n节点数，m边数
    scanf("%d %d", &n, &m);
    int G[MAX_NUM][MAX_NUM]; // 邻接矩阵表示图
    // 初始化图，初始时所有节点孤立，不可达
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                G[i][j] = 0;
            else
                G[i][j] = G[j][i] = ~(1<<31);
        }
    }
    int x, y, cost;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &x, &y, &cost);
        G[x][y] = G[y][x] = cost;
    }
    printf("%d", prim(G, n));
}

// 用邻接矩阵存储图，时间复杂度O(n * n)
int prim(int G[][MAX_NUM], int n) {
    // lowcost[i] 记录节点i到生成树的距离
    int lowcost[n], path[n]; // path记录路径
    int sum = 0;
    path[0] = -1;
    lowcost[0] = 0; // 初始最小生成树，任选一个节点加入（这里选节点1）
    for (int i = 1; i < n; i++) {
        lowcost[i] = G[0][i];
        path[i] = 0;
    }

    for (int i = 1; i < n; i++) {
        // 寻找距离最近的节点
        int minDis = ~(1 << 31), minId = -1;
        for (int j = 0; j < n; j++) {
            if (lowcost[j] == 0) continue; // 0表示已经加入最小生成树，跳过
            if (lowcost[j] < min_dis) {
                minDis = lowcost[j];
                minId = j;
            }
        }
        if (minId == -1) {
            return -1; // 图不连通，没有生成树
        }

        sum += minDis;
        lowcost[minId] = 0;

        // 更新剩余节点的距离
        for (int j = 0; j < n; j++) {
            if (lowcost[j] == 0)
                continue;
            if (G[minId][j] < lowcost[j]) {
                lowcost[j] = G[minId][j];
                path[j] = minId;
            }
        }
    }
    return sum;
}