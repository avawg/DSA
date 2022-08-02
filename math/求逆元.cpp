#include <iostream>
using namespace std;

typedef long long LL;

int qmi(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        b >>= 1;
    }
    return res;
}

int main() {
    int n, a, p;
    scanf("%d", &n);
    while (n--) {
        scanf("%d%d", &a, &p);
        if (a % p)
            printf("%d\n", qmi(a, p - 2, p));
        else
            puts("impossible");
    }
}