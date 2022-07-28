#include <iostream>
using namespace std;

const int N = 100010;
int h[N], cnt;

// 上浮
void up(int i) {
    while (i > 1) {
        int j = i / 2;
        if (h[j] > h[i]) {
            swap(j, i);
            i = j;
        } else break;
    }
}

// 下沉
void down(int i) {
    while (2 * i <= cnt) {
        int j = 2 * i;
        if (j + 1 <= cnt && h[j + 1] < h[j]) j++;
        if (h[i] > h[j]) {
            swap(i, j);
            i = j;
        } else break;
    }
}

void init() {
    for (int i = cnt / 2; i >= 1; i--) down(i);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &h[i]);
    }

    init(); // 初始大顶堆，时间复杂度O(n)

    // 插入节点
    int x;
    scanf("%d", &x);
    h[++cnt] = x;
    up(cnt);

    printf("%d\n", h[1]); // 最小值

    // 删除最小值
    swap(1, cnt--);
    down(1);
    return 0;
}