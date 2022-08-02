#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200010;
struct Edge {
    int d, a, b;
    bool operator< (const Edge &W) {
        return d < W.d;
    }
} edegs[N];
int p[N], n, m;

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void kruskal() {
    for (int i = 0; i <= n; i++) p[i] = i;

    sort(e, e + m);
    int cnt = 0, sum = 0;
    for (int i = 0; i < m; i++) {
        int a = edges[i].a, b = edges[i].b;
        int pa = find(a), pb = find(b);
        if (pa == pb) continue;
        else {
            cnt++;
            p[pa] = pb;
            sum += edegs[i].d;
        }
    }
    if (cnt == n - 1) cout << sum;
    else cout << "impossible";
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edegs[i] = {a, b, c};
    }
    kruskal();
}
