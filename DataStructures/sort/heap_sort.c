#include <stdio.h>

void swap(int nums[], int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

// 调整大顶堆，时间复杂度O(logn)
void maxHeapify(int nums[], int i, int heapSize) {
    int t = nums[i];
    while (i < heapSize) {
        // 取较大的孩子节点，下标从0开始
        int j = 2 * i + 1;
        if (j + 1 < heapSize && nums[j+1] > nums[j]) {
            j++;
        }
        if (j >= heapSize || nums[j] < t) {
            break;
        }
        nums[i] = nums[j];
        i = j;
    }
    nums[i] = t;
}

// 构建初始大顶堆，时间复杂度O(n)
void buildMaxHeap(int nums[], int n) {
    for (int i = (n - 2) / 2; i >= 0; i--) {
        maxHeapify(nums, i, n);
    }
}

// 堆排序，时间复杂度O(nlogn)
void heapSort(int nums[], int n) {
    buildMaxHeap(nums, n);
    for (int i = n - 1; i >= 0; i--) {
        swap(nums, 0, i);
        maxHeapify(nums, 0, i);
    }
}

int main() {
    int nums[] = {20, 15, 55, 25, 44, 78, 100, 52, 37, 90};
    int n = sizeof(nums) / sizeof(nums[0]);
    heapSort(nums, n);
    for (int i = 0; i < n; ++i)
        printf("%d ", nums[i]);
	return 0;
}