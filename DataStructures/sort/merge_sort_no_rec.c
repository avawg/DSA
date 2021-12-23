#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef int ElementType;
// 归并，数组nums [left, mid], [mid + 1, right]是有序的
// 在递归函数内部申请temp，会造成持续的内存申请释放，时间复杂度O(n)
void merge(ElementType nums[], ElementType temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
    	if (nums[i] <= nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }
    while (i <= mid)
        temp[k++] = nums[i++];
    while (j <= right)
		temp[k++] = nums[j++];
	// 拷贝回数组nums
    for (i = left, k = 0; i <= right; i++)
        nums[i] = temp[k++];
}

// 时间复杂度O(nlogn)
void mergeSort(ElementType nums[], int N) { // 定义接口
    ElementType * temp = (ElementType *) malloc(N * sizeof(ElementType));
    if (temp == NULL) {
        printf("空间不足");
        return ;
    }
    for (int length = 1;  ; length *= 2) {
        int num = N % length == 0 ? N / length : floor(N / length) + 1; // 分成num个片段
        if (num == 1)
            break;
        for (int i = 0; i < num; i += 2) {
            int left = i * length;
            int mid = left + length - 1;
            int right = left + 2 * length - 1;
            if (i == num - 1 || i == num - 2) { // 判断最后一个片段是否越界
                mid = mid > N - 1 ? N - 1 : mid;
                right = N - 1;
            }
            merge(nums, temp, left, mid, right);
        }
    }
    free(temp);
}

int main() {
    ElementType nums[] = {20, 100, 15, 55, 25, 44, 78, 100, 52, 37, 90};
    mergeSort(nums, sizeof(nums) / sizeof(nums[0]));
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); ++i)
        printf("%d ", nums[i]);
	return 0;
}