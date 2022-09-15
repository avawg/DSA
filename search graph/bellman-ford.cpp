#include <iostream>
#include <cstring>
using namespace std;

const int N = 510, M = 10010;
struct Edge{
    int a, b, d;
} edges[M];

int d[N], backup[N];
int n, m, k;

void bellman_ford() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;

    // 不超过k条边的最短距离
    for (int i = 0; i < k; i++) {
        memcpy(backup, d, sizeof d);
        for (int j = 0; j < m; j++) {
            auto e = edges[j];
            d[e.b] = min(d[e.b], backup[e.a] + e.d);
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }

    bellman_ford();

    if (d[n] > 0x3f3f3f3f / 2) cout << "impossible";
    else cout << d[n];
}
