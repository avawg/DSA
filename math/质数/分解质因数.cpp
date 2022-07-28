#include <iostream>
using namespace std;

void devide(int x) {
    // 最多只有一个大于sqrt(n)的质因子
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) { // i 一定是质数
            int s = 0;
            while (x % i == 0) x /= i, s++;
            printf("%d %d\n", i, s);
        }
    }
    if (x > 1) printf("%d %d\n", x, 1);
    printf("\n");
}

int main() {
    int n, x;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &x);
        devide(x);
    }
}