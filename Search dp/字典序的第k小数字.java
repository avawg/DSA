/**
 * 字典序的第K小数字
 * 给定整数 n 和 k，返回  [1, n] 中字典序第 k 小的数字。
 * 示例 1:
 *   输入: n = 13, k = 2
 *   输出: 10
 *   解释: 字典序的排列是 [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]，所以第二小的数字是 10。
 * 1 <= k <= n <= 109
 */
class Solution {
    public int findKthNumber(int n, int k) {
        // 缩小搜素范围
        int num = 1;
        while (k > 1) {
            int cnt = find(num, n);
            if (cnt >= k) { // 在子树中
                k--;
                num *= 10;
            } else { // 不在
                k -= cnt;
                num++;
            }
        }
        return num;
    }

    // 搜索以num开头的字典树节点数目
    int find(long num, long n) {
        long next = num + 1;
        int ans = 0;
        while (num <= n) {
            ans += Math.min(n + 1, next) - num;
            num *= 10;
            next *= 10;
        }
        return ans;
    }
}