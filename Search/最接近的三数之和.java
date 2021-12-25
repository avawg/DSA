/**
 * 给你一个长度为n的整数数组nums和一个目标值target。请你从nums中选出三个整数，使它们的和与target最接近。
 * 返回这三个数的和。
 * 假定每组输入只存在恰好一个解。
 * 提示:   3 <= nums.length <= 1000
 *        -1000 <= nums[i] <= 1000
 *        -104 <= target <= 104
 */
class Solution {
    public int threeSumClosest(int[] nums, int target) {

        Arrays.sort(nums);
        int n = nums.length;
        int best = 30000;
        // 枚举a
        for (int i = 0; i < n; i++) {
            // 保证和上一次枚举的元素不相等
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // 使用双指针枚举b和c
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return target;
                }
                if (Math.abs(sum - target) < Math.abs(best - target)) {
                    best = sum;
                }
                if (sum > target) {
                    // 如果和大于target，移动c对应的指针
                    // 移动到下一个不想等的元素
                    int k0 = k - 1;
                    while (k0 > j && nums[k0] == nums[k]) {
                        --k0;
                    }
                    k = k0;
                } else {
                    // 如果和小于target，移动b对应的指针
                    int j0 = j + 1;
                    while (j0 < k && nums[j0] == nums[j]) {
                        ++j0;
                    }
                    j = j0;
                }
            }
        }
        return best;
    }
}