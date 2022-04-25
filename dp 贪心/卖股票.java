/** 现在有一个长度为n的价格数组nums，表示某只股票的价格，每天最多买入或卖出该只股票的
    一手股票，买入或卖出没有手续费，持有的股票数目不受限制。初始资金为m元，在任意时刻
    不能透支，即资金必须大于等于0，问n天结束后拥有的最大资产是多少？
    (总资产=股票数目*价格 + 现金)
 */
import java.util.*;

public class SellStock {
    public static void main(String[] args) {
        // 读入数据
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        long[] nums = new long[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextLong();
        }
        // 动态规划
        long[][] dp = new long[n][n + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = -1;
            }
        }
        dp[0][0] = m;
        dfs(0, dp, nums, m, 0);
        
        long ans = 0;
        for (int i = 0; i <= n; i++) {
            if (dp[n - 1][i] != -1) {
                ans = Math.max(ans, dp[n - 1][i] + i * nums[n-1]);
            }
        }
        System.out.println(ans);
    }

    // 记忆化搜索
    // num持有股票数，money余额
    static void dfs(int id, long[][] dp, long[] nums, long money, int num) {
        int n = nums.length;
        if (id >= n) {
            return ;
        }

        // 不买也不卖
        if (money >= dp[id][num]) {
            dp[id][num] = money;
            dfs(id + 1, dp, nums, money, num);
        }

        // 卖股票
        if (num > 0 && money + nums[id] >= dp[id][num - 1]) {
            dp[id][num - 1] = money + nums[id];
            dfs(id + 1, dp, nums, money + nums[id], num - 1);
        }

        // 买股票
        if (money >= nums[id] && money - nums[id] >= dp[id][num + 1]) {
            dp[id][num + 1] = money - nums[id];
            dfs(id + 1, dp, nums, money - nums[id], num + 1);
        }
    }

    /**
     * 6 2 2 3 1 1 1 2               6
     * 3 2 1 1 4                     8
     * 4 2 1 1 4 1                   5
     * 3 100 10 9 8                  100
     * */
}