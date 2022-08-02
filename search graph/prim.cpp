#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;

const int N = 510, M = 200010;
int h[N], e[M], w[M], ne[M], idx;
int d[N], st[N], n, m;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void prim() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, 1});

    int cnt = 0, sum = 0;
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();

        int u = t.second;
        if (st[u]) continue;
        st[u] = true;
        cnt++;
        sum += t.first;

        for (int i = h[u]; i != -1; i = ne[i]) {
            int j = e[i];
            if (w[i] < d[j]) {
                d[j] = w[i];
                pq.push({d[j], j});
            }
        }
    }
    if (cnt == n) cout << sum;
    else cout << "impossible";
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    int x, y, z;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
    }
    prim();
}
