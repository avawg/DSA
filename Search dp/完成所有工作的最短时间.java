/**
 * 完成所有工作的最短时间
 * 给你一个整数数组jobs ，其中jobs[i]是完成第i项工作要花费的时间。
 * 请你将这些工作分配给k位工人。所有工作都应该分配给工人，且每项工作只能分配给一位工人。工人的 工作时间是完成分配给他们的所有工作花费时间的总和。
 * 请你设计一套最佳的工作分配方案，使工人的最大工作时间得以最小化 。
 * 返回分配方案中尽可能最小的最大工作时间 。
 *
 * 示例 1：
 *   输入：jobs = [3,2,3], k = 3
 *   输出：3
 *   解释：给每位工人分配一项工作，最大工作时间是 3 。
 * 1 <= k <= jobs.length <= 12
 * 1 <= jobs[i] <= 107
 */

class Solution {

    int ans = Integer.MAX_VALUE;
    int n, k;
    int[] jobs;

    public int minimumTimeRequired(int[] jobs, int k) {
        n = jobs.length;
        this.k = k;
        this.jobs = jobs;
        // 先分配时长较大的工作
        Arrays.sort(jobs);
        for (int i = 0; i < n / 2; i++) {
            int t = jobs[i];
            jobs[i] = jobs[n - 1- i];
            jobs[n - 1- i] = t;
        }
        dfs(0, new int[k], 0, 0);
        return ans;
    }

    // 搜索所有可能
    void dfs(int i, int[] sum, int used, int max) {
        if (i == n) {
            ans = Math.min(ans, max);
            return ;
        }
        if (max >= ans) {
            return ;
        }

        // 优先分配给空闲工人
        if (used < k) {
            sum[used] = jobs[i];
            dfs(i + 1, sum, used + 1, Math.max(max, sum[used]));
            sum[used] = 0;
        }
        for (int j = 0; j < used; j++) {
            sum[j] += jobs[i];
            dfs(i + 1, sum, used, Math.max(max, sum[j]));
            sum[j] -= jobs[i];
        }
    }
}
