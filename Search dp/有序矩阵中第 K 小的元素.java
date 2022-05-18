/**
 * 有序矩阵中第K小的元素
 * 给你一个n x n矩阵matrix ，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
 * 请注意，它是排序后的第k小元素，而不是第k个不同的元素。
 */

class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length;
        // 二分查找
        int lo = matrix[0][0], hi = matrix[n - 1][n - 1];
        while (lo < hi) {
            // 统计 <= mid的数目个数
            int mid = lo + (hi - lo) / 2;
            int cnt = 0;
            int r = n - 1, c = 0;
            while (r >= 0 && c < n) {
                if (matrix[r][c] <= mid) {
                    cnt += r + 1;
                    c++;
                } else {
                    r--;
                }
            }
            if (cnt >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
}
