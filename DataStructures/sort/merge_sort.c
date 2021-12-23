#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
// 归并，数组nums [left, mid] 和 [mid + 1, right]是有序的，时间复杂度O(n)
// 在递归函数内部动态申请temp，会造成持续的内存申请释放
void merge(ElementType nums[], ElementType temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
    	if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }
    while (i <= mid)
        temp[k++] = nums[i++];
    while (j <= right)
		temp[k++] = nums[j++];
	// 拷贝回数组nums
    for (i = left, k = 0; i <= right; i++)
        nums[i] = temp[k++];
}

// 从中间划分成两个子问题，时间复杂度O(nlogn)
void msort(ElementType nums[], ElementType temp[], int left, int right) {
    if (left >= right)
		return;
    int mid = (left + right) / 2;
    msort(nums, temp, left, mid);
	msort(nums, temp, mid+1, right);
    merge(nums, temp, left, mid, right);
}

void mergeSort(ElementType nums[], int N) { // 定义接口
    ElementType * temp = (ElementType *) malloc(N * sizeof(ElementType));
    if (temp != NULL) {
        msort(nums, temp, 0, N-1);
        free(temp);
    } else
        printf("空间不足");
}

int main() {
    ElementType nums[] = {20, 15, 55, 25, 44, 78, 100, 52, 37, 90};
    mergeSort(nums, sizeof(nums) / sizeof(nums[0]));
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); ++i)
        printf("%d ", nums[i]);
	return 0;
}