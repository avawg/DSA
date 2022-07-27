#include <iostream>
using namespace std;

void mergeSort(int nums[], int temp[], int l, int r) {
    if (l >= r) return ;
    int mid = (l + r) / 2;
    // 从中点分开，将左右两侧排序好
    mergeSort(nums, temp, l, mid);
    mergeSort(nums, temp, mid + 1, r);
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (nums[i] <= nums[j]) temp[k++] = nums[i++];
        else temp[k++] = nums[j++];
    }
    while (i <= mid) temp[k++] = nums[i++];
    while (j <= r) temp[k++] = nums[j++];
    for (i = l; i <= r; i++) { // 拷贝回原数组
        nums[i] = temp[i];
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int nums[n], temp[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    mergeSort(nums, temp, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    return 0;
}