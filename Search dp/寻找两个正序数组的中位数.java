/**
 * 给定两个大小分别为m和n的正序（从小到大）数组nums1和nums2。请你找出并返回这两个正序数组的 中位数 。
 * 算法的时间复杂度应该为 O(log (m+n))
 */

class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int length1 = nums1.length, length2 = nums2.length;
        int totalLength = length1 + length2;
        if (totalLength % 2 == 1) {
            double median = findKthElement(nums1, nums2, totalLength / 2 + 1);
            return median;
        } else {
            double median = (findKthElement(nums1, nums2, totalLength / 2) + findKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
            return median;
        }

    }

    public int findKthElement(int[] nums1, int[] nums2, int k) {
        /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
         * 这里的 "/" 表示整除
         * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-1] 共计 k/2 个
         * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-1] 共计 k/2 个
         * 取 pivot = min(pivot1, pivot2)，两个数组中小于 pivot 的元素共计不会超过 (k/2 - 1) + (k/2-1) <= k-2 个
         * 这样 pivot 本身最大也只能是第 k-1 小的元素
         * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
         * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
         * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
         */
        int length1 = nums1.length, length2 = nums2.length;
        int l1 = 0, l2 = 0;
        while (true) {
            if (l1 == nums1.length) {
                return nums2[l2 + k - 1];
            }
            if (l2 == nums2.length) {
                return nums1[l1 + k - 1];
            }
            if (k == 1) {
                return Math.min(nums1[l1], nums2[l2]);
            }
            int newIndex1 = Math.min(l1 + k / 2 - 1, length1 - 1);
            int newIndex2 = Math.min(l2 + k / 2 - 1, length2 - 1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2) {
                k -= newIndex1 - l1 + 1;
                l1 = newIndex1 + 1;
            } else {
                k -= newIndex2 - l2 + 1;
                l2 = newIndex2 + 1;
            }
        }
        // return -1;
    }
}
