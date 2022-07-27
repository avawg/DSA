
#include <iostream>
using namespace std;

// 快速选择 第k小的数 O(n)
void qsort(int nums[], int l, int r, int k) {
    int mid = (l + r) / 2;
    swap(nums[l], nums[mid]);
    int x = nums[l];
    int i = l + 1, j = l + 1;
    for (; i <= r; i++) {
        if (nums[i] <= x) {
            swap(nums[j++], nums[i]);
        }
    }
    j--;
    swap(nums[l], nums[j]);
    // 缩小搜索范围，朝目标靠近
    if (j > k - 1) qsort(nums, l, j - 1, k);
    else if (j < k - 1) qsort(nums, j + 1, r, k);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
    qsort(nums, 0, n - 1, k);
    printf("%d", nums[k - 1]);
    return 0;
}