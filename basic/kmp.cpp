#include <iostream>
using namespace std;

int main() {
    string p, s;
    cin >> p >> s;
    int n = p.length(), m = s.length();
    int dp[n];
    dp[0] = 0;
    // dp[i] 表示p[0:i]除自身外最长匹配地前后缀子串长度
    for (int i = 1, j = 0; i < n; i++) {
        while (j && p[i] != p[j]) j = dp[j - 1];
        if (p[i] == p[j]) ++j;
        dp[i] = j;
    }

    // 和text串匹配，比较次数[m，2m]，时间复杂度O(m)
    for (int i = 0, j = 0; i < m; i++) {
        while (j && s[i] != p[j]) j = dp[j - 1];
        if (s[i] == p[j]) j++; // j最多增加m次
        if (j == n) {
            cout << i - n + 1 << " ";
            j = dp[j - 1];
        }
    }
    return 0;
}