#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 150010;
int h[N], e[N], w[N], ne[N], idx;
int d[N], st[N], n, m;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra() {
    memset(d, 0x3f, sizeof d);
    d[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;

    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (d[t] + w[i] < d[j]) {
                d[j] = d[t] + w[i];
                if (!st[j]) {
                    st[j] = true; q.push(j);
                }
            }
        }
    }
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    int x, y, z;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
    }

    dijkstra();
    if (d[n] > 0x3f3f3f3f / 2) cout << "impossible";
    else cout << d[n];
}
