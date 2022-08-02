#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
int h[N], e[N], ne[N], idx;

int in[N], n, m;

void add(int a, int b) {
    e[idx] = b; ne[idx] = h[a]; h[a] = idx++;
}

void toposort() {
    int q[N], hh = 0, tt = -1;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) q[++tt] = i;
    }

    while (hh <= tt) {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (--in[j] == 0) {
                q[++tt] = j;
            }
        }
    }
    if (hh == n) {
        for (int i = 0; i < n; i++) printf("%d ", q[i]);
    } else {
        cout << -1;
    }
}

int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        add(a, b);
        in[b]++;
    }
    toposort();
}
