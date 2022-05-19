#include <iostream>
using namespace std;

/**
 * 给定一个 n * n 的棋盘，'B'黑子 'W'白子 'N'没有棋子
 * 棋子上下左右周边没有位置的棋子称为棋子的气，相同颜色相连的棋子共用气
 * 只有两口气或以上的棋子才是活子，求黑棋和白棋活子数目。
 * 3WWWNBBBNN
 * 5NNWBWB BBWBBB WWWBBB NWWWBB WNNWBN
 * 5NNWBWBBWBBWWWBBNWWWBWNNWB
 */

int n = 0, qi = 0, cnt = 0;
char grid[20][20];
int vis[20][20];

// dfs找联通分支并标记边界
void dfs(int r, int c) {
    ++cnt;
    int dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    for (int i = 0; i < 4; i++) {
        int nr = r + dirs[i][0], nc = c + dirs[i][1];
        if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
            continue;
        }
        // 标记边界
        if (grid[nr][nc] == 'N' && vis[nr][nc] != 2) {
            vis[nr][nc] = 2;
            ++qi;
        }
        if (grid[nr][nc] == grid[r][c] && vis[nr][nc] == 0) {
            vis[nr][nc] = 1;
            dfs(nr, nc);
        }
    }
}

int main() {
    // 数据预处理
    string s;
    cin >> s;
    int k = 1;
    n = s[0] - '0';
    if (s[1] >= '0' && s[1] <= '9') {
        n = n * 10 + s[1] - '0';
        k = 2;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = s[k++];
            vis[i][j] = 0;
        }
    }

    // 搜索
    int black = 0, white = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            // 未访问过 求联通分支
            if (grid[r][c] != 'N' && vis[r][c] == 0) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (vis[i][j] == 2) {
                            vis[i][j] = 0;
                        }
                    }
                }
                cnt = qi = 0;
                vis[r][c] = 1;
                dfs(r, c);
                if (qi >= 2) {
                    if (grid[r][c] == 'B') {
                        black += cnt;
                    } else {
                        white += cnt;
                    }
                }
            }
        }
    }
    cout << "B " << black << " W " << white;
}
