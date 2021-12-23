#include <stdio.h>
#include <string.h>

int kmp(char *text, char *pat);

int main() {
    char *text = "abcdabcdabde";
    char *pat = "abcdabd";
    printf("%d", kmp(text, pat));
    return 0;
}

// 算法时间复杂度 O(n + m) !!!
int kmp(char *text, char *pat) {
    int n = strlen(pat);
    // prefix[i] 表示pat[0:i]除自身外最长匹配地前后缀子串长度
    int prefix[n];

    // 动态规划求prefix，比较次数[n, 2n]，时间复杂度O(n)
    prefix[0] = 0;
    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && pat[i] != pat[j]) {
            j = prefix[j - 1];
        }
        if (pat[i] == pat[j]) {
            j++;
        }
        prefix[i] = j;
    }

    int m = strlen(text);
    // 和text串匹配，比较次数[m，2m]，时间复杂度O(m)
    for (int i = 0, j = 0; i < m; i++) {
        while (j > 0 && text[i] != pat[j]) {
            j = prefix[j - 1];
        }
        if (text[i] == pat[j]) {
            j++;
        }
        if (j == n) {
            return i + 1 - n; // j == n 则pat模式串[0, n-1]位都匹配上了, 返回主串第一个匹配的下标
        }
    }
    return -1;
}