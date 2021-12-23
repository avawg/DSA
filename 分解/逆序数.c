#include <stdio.h>
/*
   考虑1, 2,..., n(n<100000)的排列i1, i2, ..., in, 如果其中存在j, k, 满足j < k
   且 ij > ik, 那么就称(ij, ik)是这个排列的一个逆序。一个排列含有逆序的个数称为这个排列的逆序数。
   现给定1, 2, ..., n的一个排列, 求它的逆序数
*/
const int MAX_SIZE = 100010;
long long cnt = 0;

// 时间复杂度 O(nlogn)
// nums[left:mid], nums[mid+1:right]是两个排好序的逆序列
void sortAndCount(int nums[], int left, int mid, int right) {
  int i = left, j = mid + 1, k;
  // 计算逆序数
  for (i = left; i <= mid; i++) {
    for (; j <= right && nums[j] >= nums[i]; j++)
      ;
    cnt += right - j + 1;
  }
  i = left, j = mid + 1, k = 0;
  int temp[right - left + 1];
  // 归并
  while (i <= mid && j <= right) {
    if (nums[i] >= nums[j])
      temp[k++] = nums[i++];
    else
      temp[k++] = nums[j++];
  }
  while (i <= mid) temp[k++] = nums[i++];
  while (j <= right) temp[k++] = nums[j++];
  for (k = 0, i = left; i <= right; i++) nums[i] = temp[k++];
}

// 归并
void mergeSortAndCount(int nums[], int left, int right) {
  if (left <= right) {
    int mid = (left + right) / 2;
    mergeSortAndCount(nums, left, mid);
    mergeSortAndCount(nums, mid + 1, right);
    sortAndCount(nums, left, mid, right);
  }
}

int main() {
  int n, nums[MAX_SIZE];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
  mergeSortAndCount(nums, 0, n - 1);
  printf("%lld", cnt);
  return 0;
}