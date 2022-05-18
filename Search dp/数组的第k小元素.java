/**
 * 数组中的第K个最小元素
 * 给定整数数组nums和整数k，请返回数组中第k个最小的元素。
 * 请注意，你需要找的是数组排序后的第k个最小的元素，而不是第k个不同的元素。
 * 示例 1:
 *   输入: [3,2,1,5,6,4] 和 k = 2
 *   输出: 5
 */

class Solution {
    public int findKthSmallest(int[] nums, int k) {
        int n = nums.length;
        int l = 0, r = n - 1;
        while (true) {
            if (l == r) {
                return nums[l];
            }
            int pivot = nums[l], i = l + 1, j = l + 1;
            for ( ; i <= r; i++) {
                if (nums[i] <= pivot) {
                    swap(nums, i, j);
                    j++;
                }
            }
            int mid = j - 1;
            // nums[l, mid - 1] <= nums[mid], nums[mid + 1, r] > nums[mid]
            swap(nums, l, mid);
            int num = mid - l + 1;
            // 缩小搜索范围，朝目标靠近
            if (num == k) {
                return nums[mid];
            } else if (num > k) {
                r = mid - 1;
            } else {
                l = mid + 1;
                k -= num;
            }
        }
    }

    void swap(int[] nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}
