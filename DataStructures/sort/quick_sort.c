#include <stdio.h>

void swap(int nums[], int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

// 一次快排，时间复杂度O(n)
int partition(int nums[], int left, int right) {
    int pivot = nums[left]; // 以nums[left]为枢轴
    int i = left + 1, j = left + 1;
    // [left + 1, i) 所有元素都 <= pivot，[i, j)都 > pivot
    while (j <= right) {
        if (nums[j] <= pivot) {
            swap(nums, j, i);
            i++;
        }
        j++;
    }
    swap(nums, left, i - 1);
    return i - 1;
}

// 快排数组nums left到right间元素，时间复杂度O(nlogn)
void qsort(int nums[], int left, int right) {
    if (left >= right) {
        return ;
    }
    int mid = partition(nums, left, right);
    qsort(nums, left, mid - 1);
    qsort(nums, mid + 1, right);
}

int main(){
	int nums[] = {1, 3, 99, 0, 30, 5, 1000, 999, 32, 9};
    int n = sizeof(nums) / sizeof(nums[0]);
	qsort(nums, 0, n - 1);
	for (int i = 0; i < n; ++i) {
        printf("%d ", nums[i]);
    }
	return 0;
}