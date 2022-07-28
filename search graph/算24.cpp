#include <iostream>
#include <cmath>
using namespace std;

// 判断是否使24，可能是浮点数
bool isZero(double x) {
    return fabs(x) < 1e-6;
}

// 	计算n个数，能否得到24，时间复杂度O(1)
bool count24(double a[], int n) {
    if (n == 1)
        return isZero(a[0] - 24);
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
            if (count24(b, r + 1)) return true;
            b[r] = a[i] - a[j];
            if (count24(b, r + 1)) return true;
            b[r] = a[j] - a[i];
            if (count24(b, r + 1)) return true;
            b[r] = a[i] * a[j];
            if (count24(b, r + 1)) return true;
            if (!(isZero(a[j]))) {
                b[r] = a[i] / a[j];
                if (count24(b, r + 1)) return true;
            }
            if (!(isZero(a[i]))) {
                b[r] = a[j] / a[i];
                if (count24(b, r + 1)) return true;
            }
        }
    }
    return false;
}

int main() {
    double a[4];
    for (int i = 0; i < 4; ++i) {
        scanf("%lf", &a[i]);
    }
    puts(count24(a, 4)? "YES": "NO");
    return 0;
}
