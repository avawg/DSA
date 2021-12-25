#include <stdio.h>

// 时间复杂度 O(2^n)
void hanoi(int n, char src, char mid, char dst, int* cnt) {
    if (n == 1) {
        printf("1: %c->%c\n", src, dst);
        *cnt += 1;
    }
    else {
        hanoi(n-1, src, dst, mid, cnt);
        printf("%d: %c->%c\n", n, src, dst);
        *cnt += 1;
        hanoi(n-1, mid, src, dst, cnt);
    }
}

int main() {
    int n, cnt = 0;
    printf("请输入盘子个数n：\n");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C', &cnt);
    printf("总移动次数为：%d\n", cnt);
    return 0;
}