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