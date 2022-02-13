/**
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 */

 class Solution {
    public String longestPalindrome(String s) {

        int len = s.length();
        // dp[i][j]表示s[i:j]是否是回文子串
        boolean[][] dp = new boolean[len][len];
        for (int i = 0; i < len; i++) {
            dp[i][i] = true;
        }
        int maxLen = 1;
        int begin = 0;
        // 枚举子串长度
        for (int L = 2; L <= len; L++) {
            // 枚举左边界
            for (int i = 0; i < len; i++) {
                int j = L + i - 1;
                if (j >= len) {
                    break;
                }
                if (s.charAt(i) == s.charAt(j)) {
                    if (L <= 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                if (dp[i][j] && L > maxLen) {
                    maxLen = L;
                    begin = i;
                }
            }
        }
        return s.substring(begin, begin + maxLen);
    }
}