#include <iostream>
#include <cstring>
using namespace std;

const int N = 210;
int g[N][N], d[N][N], n;

// floyd算法，时间复杂度 O(n^3)
void floyd() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            d[i][j] = g[i][j];
    }
    // 第k轮， d[i][j]表示 节点i和j只经过 id<=k 的节点连通的最小距离
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
}

int main() {
    int m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (i == j) g[i][j] = 0;
            else g[i][j] = 1e9;
    while (m --) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }

    floyd();

    while (k--) {
        int a, b;
        cin >> a >> b;
        if (d[a][b] > 1e9 / 2) cout << "impossible\n";
        else cout << d[a][b] << endl;
    }
}