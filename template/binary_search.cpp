#include <iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int nums[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

    int x; scanf("%d", &x);

    // 二分查找 >= x的最小值
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] >= x) r = mid;
        else l = mid + 1;
    }

    // 二分查找 <= x的 最大值
    l = 0; r = n - 1;
    while (l < r) {
        int mid = (l + r + 1) / 2; // +1 避免死循环
        if (nums[mid] <= x) l = mid;
        else r = mid - 1;
    }
    return 0;
}