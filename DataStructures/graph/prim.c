#include <stdio.h>

const int MAX_NUM = 110;

int prim(int G[][MAX_NUM], int n); 

int main() {
    int n, m; // n节点数，m边数
    scanf("%d %d", &n, &m);
    int G[MAX_NUM][MAX_NUM]; // 邻接矩阵表示图
    // 初始化图，初始时所有节点孤立，不可达
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
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
    int lowcost[n+1], path[n+1]; // path记录路径
    int sum = 0;
    path[1] = -1;
    lowcost[1] = 0; // 初始最小生成树，任选一个节点加入（这里选节点1）
    for (int i = 2; i <= n; i++) {
        lowcost[i] = G[1][i];
        path[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        // 寻找与最小生成树距离最小的节点
        int min_dis = ~(1 << 31), min_id;
        for (int j = 1; j <= n; j++) {
            if (lowcost[j] == 0) continue; // 0表示已经加入最小生成树，跳过
            if (lowcost[j] < min_dis) {
                min_dis = lowcost[j];
                min_id = j;
            }
        }
        sum += min_dis; // 记录总距离
        lowcost[min_id] = 0; // 将距离最小的节点加入生成树

        // 比较剩余节点与min_id的距离，若小于相应lowcost，则更新
        for (int j = 1; j <= n; j++) {
            if (lowcost[j] == 0)
                continue; // 0表示已经加入最小生成树，跳过
            if (G[j][min_id] < lowcost[j]) {
                lowcost[j] = G[j][min_id];
                path[j] = min_id;
            }         
        }
    }
    return sum;
}