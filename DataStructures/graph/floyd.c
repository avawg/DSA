#include <stdio.h>

const int MAX_NUM = 100;
int G[MAX_NUM][MAX_NUM]; // 邻接矩阵表示图
void floyd(int G[][MAX_NUM], int n);
int main() {
    int n, m; // n节点数, m边数
    scanf("%d %d", &n, &m);
    // 初始化图，初始时所有节点孤立，不可达
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                G[i][j] = 0;
            else
                G[i][j] = G[j][i] = ~(1 << 31);
        }
    }
    int x, y, cost;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &x, &y, &cost);
        G[x][y] = G[y][x] = cost;
    }
    floyd(G, n);
    return 0;
}

// floyd算法，时间复杂度 O(n^3)
void floyd(int G[][MAX_NUM], int n) {
    for (int k = 1; k <= n; k++) { // 第k轮， G[i][j]表示 节点i和j只经过 id<=k 的节点连通的最小距离
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (G[i][k] == ~(1 << 31) || G[k][j] == ~(1 << 31)) continue;
                if (G[i][j] > G[i][k] + G[k][j]) { // k轮，中间节点在原来k-1轮的基础上加上k
                    G[i][j] = G[i][k] + G[k][j];
                }
            }
        }
    }
}
