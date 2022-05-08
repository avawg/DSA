/**
 * 数组中占比超过一半的元素称之为主要元素。给定一个大小为n的数组，找出其中的主要元素。若没有，返回-1。
 * 请设计时间复杂度为 O(N) 、空间复杂度为 O(1) 的解决方案。
 *
 */

class Solution {
    /*
    Boyer-Moore 投票算法：
        假设整个数组的众数记做maj，则最初的数组中a的数量大于其余所有数。当采用count计数的时候有两种情况：
        1）假设candidate等于maj，则当count从1变为0的过程，此区间内maj的数量等于其余数的数量，
           因此以count=0为分界线，数组右端部分的众数仍然为maj
        2）假设candidate不等于maj，则当count从1变为0的过程， 此区间内maj的数量小于等于其余数的数量，
           因此以count=0为分界线，数组右端部分的众数仍然为maj
        因此，以count=0可以将整个原始数组分为若干部分，count=0右端部分的数组中的众数永远是maj，最终必然会筛选出a
*/
    public int majorityElement(int[] nums) {
        int n = nums.length;
        int count = 0, candidate = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate ? 1 : -1);
        }
        // 判断candidate是否是真的多数元素
        count = 0;
        for (int num : nums) {
            count += (num == candidate ? 1 : 0);
        }
        return count > n / 2 ? candidate : -1;
    }
}
