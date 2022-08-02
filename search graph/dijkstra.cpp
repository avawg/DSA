#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;

const int N = 150010, M = 150010;
int h[N], e[M], w[M], ne[M], idx;
int d[N], st[N], n, m;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({d[1], 1});

    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();

        int u = t.second;
        if (st[u]) continue;
        st[u] = true;

        for (int i = h[u]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[u] + w[i] < d[j]) {
                d[j] = d[u] + w[i];
                pq.push({d[j], j});
            }
        }
    }
    if (d[n] == 0x3f3f3f3f) return -1;
    else return d[n];
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    int x, y, z;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
    }
    cout << dijkstra();
}
