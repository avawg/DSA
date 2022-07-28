#include <iostream>
using namespace std;

const int N = 100010;
int p[N];

// 查找
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int p[n];
    for (int i = 0; i < n; i++) p[i] = i;

    char c;
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("\n%c %d %d", &c, &a, &b);
        int pa = find(p, a), pb = find(p, b);
        if (c == 'M') p[pa] = pb; // 合并
        else printf(pa == pb ? "Yes\n" : "No\n");
    }
    return 0;
}