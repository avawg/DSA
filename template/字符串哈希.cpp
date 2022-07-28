#include <iostream>
using namespace std;

typedef unsigned long long ULL;
const int N = 100010, P = 131;

ULL p[N], h[N];

ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    string s;
    int n, m;
    scanf("%d%d", &n, &m);
    cin >> s;
    p[0] = 1;
    for (int i = 0; i < n; i++) {
        p[i + 1] = p[i] * P;
        h[i + 1] = h[i] * P + s[i];
    }

    int l1, r1, l2, r2;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
        puts(get(l1, r1) == get(l2, r2) ? "Yes" : "No");
    }
    return 0;
}