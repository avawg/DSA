#include <stdio.h>
#include <math.h>
#include <stdbool.h>
/*
	给出4个小于10个正整数，你可以使用加减乘除4种运算以及括号把这4个数连接起来得到一个表达式。
	现在的问题是，是否存在一种方式使得得到的表达式的结果等于24?
	对于5，5，5，1，我们知道5 * (5 – 1 / 5) = 24，因此可以得到24。又比如，对于1，1，4，2，我们怎么都不能得到24。
*/

// 判断是否使24，可能是浮点数
bool isZero(double x) {
    return fabs(x) < 1e-6;
}

// 	计算n个数，能否得到24，时间复杂度O(1)
bool count24(double a[], int n) {
    if (n == 1)
        return isZero(a[0]-24);
    double b[5];
	// 任取2个数, 先计算 + - * / 结果
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int r = 0;
            // 将剩余的数拷贝进数值b
            for (int k = 0; k < n; k++) {
                if (k != i && k != j)
                    b[r++] = a[k];
            }
            // 分别计算 + - * / 结果
            b[r] = a[i] + a[j];
            if (count24(b, r+1)) return true;
            b[r] = a[i] - a[j];
            if (count24(b, r+1)) return true;
            b[r] = a[j] - a[i];
            if (count24(b, r+1)) return true;
            b[r] = a[i] * a[j];
            if (count24(b, r+1)) return true;
            if (!(isZero(a[j]))) {
                b[r] = a[i] / a[j];
                if (count24(b, r+1)) return true;
            }
            if (!(isZero(a[i]))) {
                b[r] = a[j] / a[i];
                if (count24(b, r+1)) return true;
            }
        }
    }
    return false;
}

int main() {
    double a[4];
    while (true) {
        for (int i = 0; i < 4; ++i) {
            scanf("%lf", &a[i]);
        }
        if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0) break;
        printf(count24(a, 4)? "YES\n": "NO\n");
    }
    return 0;
}
