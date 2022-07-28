#include <iostream>
using namespace std;

int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x == 1) puts("No");
        else {
            bool flag = true;
            // 两个因子必定成对出现
            for (int i = 2; i <= x / i; i++) {
                if (x % i == 0) {
                    flag = false; break;
                }
            }
            puts(flag ? "Yes" : "No");
        }
    }
}