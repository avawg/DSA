#include <iostream>
using namespace std;

const int N = 100010;
int st[N], tt = 0;

int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        while (tt && x <= st[tt]) { // 找小于x的最右侧元素
            tt--;
        }
        printf("%d ", tt > 0 ? st[tt] : -1);
        st[++tt] = x;
    }
    return 0;
}