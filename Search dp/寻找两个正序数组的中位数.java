/**
 * 给定两个大小分别为m和n的正序（从小到大）数组nums1和nums2。请你找出并返回这两个正序数组的 中位数 。
 * 算法的时间复杂度应该为 O(log (m+n))
 */

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length, n = nums2.length;
        if ((m + n) % 2 == 0) {
            int left = find(nums1, nums2, (m + n) / 2);
            int right = find(nums1, nums2, (m + n) / 2 + 1);
            return (left + right) / 2.0;
        } else {
            return find(nums1, nums2, (m + n) / 2 + 1);
        }
    }

    // 在nums1, nums2两个正序数组中找第k小的数
    int find(int[] nums1, int[] nums2, int k) {
        int m = nums1.length, n = nums2.length;
        int l1 = 0, r1 = m - 1;
        int l2 = 0, r2 = n - 1;
        // 淘汰部分数据, 缩小搜索范围, 二分
        while (true) {
            if (l1 > r1) {
                return nums2[l2 + k - 1];
            }
            if (l2 > r2) {
                return nums1[l1 + k - 1];
            }
            if (k == 1) {
                return Math.min(nums1[l1], nums2[l2]);
            }
            int mid1 = Math.min(l1 + k / 2 - 1, r1);
            int mid2 = Math.min(l2 + k / 2 - 1, r2);
            if (nums1[mid1] <= nums2[mid2]) {
                k -= mid1 - l1 + 1;
                l1 = mid1 + 1;
            } else {
                k -= mid2 - l2 + 1;
                l2 = mid2 + 1;
            }
        }
    }
}
