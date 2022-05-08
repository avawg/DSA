/**
 * 给你一个长度为 n 的整数数组 nums ，其中 nums 的所有整数都在范围 [1, n] 内，且每个整数出现 一次 或 两次 。
 * 请你找出所有出现两次的整数，并以数组形式返回。
 * 你必须设计并实现一个时间复杂度为 O(n) 且仅使用常量额外空间的算法解决此问题。
 */

 class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        int n = nums.length;
        // 抽屉原理，把nums[i]放在nums[i] - 1位置处
        for (int i = 0; i < n; i++) {
            while (nums[nums[i] - 1] != nums[i]) {
                swap(nums, i, nums[i] - 1);
            }
        }
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                ans.add(nums[i]);
            }
        }
        return ans;
    }

    void swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
