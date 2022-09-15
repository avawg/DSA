#include <iostream>
using namespace std;

const int N = 2010, mod = 1e9 + 7;

int main() {
    int c[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++)
            if (!j) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i  - 1][j - 1]) % mod;
    }

    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        printf("%lld\n", c[a][b]);
    }
}