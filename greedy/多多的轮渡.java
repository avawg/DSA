/**
 * 多多负责轮渡，渡船每次最多可以运送n辆车，渡江单程需要x分钟，往返需要2*x分钟
 * 已知今天需要过江的m辆汽车的到达时间nums[i]，则最早什么时候能把所有的车辆运送到对岸？
 * 输入:
 *     m n x nums[0] nums[1] .... nums[m - 1]
 *     3 2 10 10 40 30    50
 *     10 2 10 0 10 20 30 40 50 60 70 80 90   100
 */

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        int[] nums = new int[m];
        for (int i = 0; i < m; i++) {
            nums[i] = scanner.nextInt();
        }

        Arrays.sort(nums);
        int time = 0, i = 0;
        while (i < m) {
            int j = i;
            for ( ; j < Math.min(i + n, m) - 1; j++) {
                if (nums[j + 1] >= nums[j] + 2 * x) {
                    break;
                }
            }
            if (j == m - 1) {
                int ans = Math.max(time, nums[m - 1]) + x;
                System.out.println(ans);
                break;
            }
            time = Math.max(time, nums[j]) + 2 * x;
            i = j + 1;
        }
    }
}
