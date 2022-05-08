/**
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 */

 class Solution {
    public String longestPalindrome(String s) {

        int n = s.length();
        if (n == 0) {
            return "";
        }
        // dp[i][j]表示s[i:j]是否是回文子串
        boolean[][] dp = new boolean[n][n];
        String ans = "";
        // 枚举子串长度
        for (int len = 1; len <= n; len++) {
            // 枚举左边界
            for (int l = 0; l < n + 1 - len; l++) {
                int r = l + len - 1;
                dp[i][j] = s.charAt(l) == s.charAt(r) && (l + 1 >= r - 1 || dp[l + 1][r - 1]);
                if (dp[i][j]) {
                    ans = s.substring(l, r + 1);
                }
            }
        }
        return ans;
    }
}
