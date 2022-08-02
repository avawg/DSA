#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 110;
int g[N][N], d[N][N], m, n;

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);
    }
    memset(d, -1, sizeof(d));

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    queue<pair<int, int>> que;
    que.push({0, 0});
    d[0][0] = 0;
    while (!que.empty()) {
        auto t = que.front();
        que.pop();
        int r = t.first, c = t.second;

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i], nc = c + dy[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !g[nr][nc] && d[nr][nc] == -1) {
                d[nr][nc] = d[r][c] + 1;
                que.push({nr, nc});
            }
        }
    }
    cout << d[m - 1][n - 1];
}