#include <iostream>
using namespace std;

typedef long long LL;
const int N = 100010, mod = 1e9 + 7;
int fact[N], infact[N];

int qmi(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % mod;
        a = (LL)a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (LL)fact[i - 1] * i % mod;
        infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }

    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        printf("%d\n", (LL)fact[a] * infact[a - b] % mod * infact[b] % mod);
    }
}