#include <iostream>
using namespace std;

void qsort(int nums[], int l, int r) {
    if (l >= r) return ;
    // 一次快排, 将 <= pivot元素移动到左侧，>= pivot元素移动到右侧
    int mid = (l + r) / 2;
    swap(nums[l], nums[mid]);
    int pivot = nums[l];
    int i = l + 1, j = l + 1;
    while (i <= r) {
        if (nums[i] <= pivot) swap(nums[i], nums[j++]);
        i++;
    }
    j--;
    swap(nums[l], nums[j]);
    qsort(nums, l, j - 1);
    qsort(nums, j + 1, r);
}

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    qsort(nums, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    return 0;
}