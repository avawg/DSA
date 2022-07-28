#include <iostream>
using namespace std;

const int N = 10;
int path[N];
int n;

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                printf("%c", path[i] == j ? 'Q' : '.');
            printf("\n");
        }
        printf("\n");
        return ;
    }
    // 尝试把第u行皇后放在第i列
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int r = 0; r < u; r++) {
            if (path[r] == i || u + i == r + path[r] || u - i == r - path[r]) {
                flag = false; break; // 冲突
            }
        }
        if (flag) {
            path[u] = i;
            dfs(u + 1);
        }
    }
}

int main() {
    scanf("%d", &n);
    dfs(0);
    return 0;
}