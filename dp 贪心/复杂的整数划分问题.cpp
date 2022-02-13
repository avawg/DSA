/**
    描述
        将正整数n 表示成一系列正整数之和，n=n1+n2+…+nk, 其中n1>=n2>=…>=nk>=1 ，k>=1 。
        正整数n 的这种表示称为正整数n 的划分。

    输入
        标准的输入包含若干组测试数据。每组测试数据是一行输入数据,包括两个整数N 和 K。
        (0 < N <= 50, 0 < K <= N)
    输出
        对于每组测试数据，输出以下三行数据:
        第一行: N划分成K个正整数之和的划分数目
        第二行: N划分成若干个不同正整数之和的划分数目
        第三行: N划分成若干个奇正整数之和的划分数目
    样例输入
        5 2
    样例输出
        2
        3
        3
*/

#include <iostream>
using namespace std;

int dp[51][51];

void reset() {
    for (int i = 1; i <= 50; i++) {
        for (int j = 1; j <= 50; j++) {
            dp[i][j] = 0;
        }
    }
}

int main() {
    int n, k;
    dp[0][0] = 1;
    while (cin >> n >> k) {
        reset();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i][j] = dp[i-1][j-1] + dp[i - j][j];
            }
        }
        cout << dp[n][k] << endl;

        reset();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i][j] = dp[i-j][j-1] + dp[i-j][j];
            }
        }
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += dp[n][i];
        }
        cout << sum << endl;

        reset();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i][j] = dp[i-1][j-1];
				if (i-2 * j > 0) {
					dp[i][j] += dp[i-2 * j][j];
				}
            }
        }
        sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += dp[n][i];
        }
        cout << sum << endl;
    }
}