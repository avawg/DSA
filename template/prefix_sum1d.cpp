#include <iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int nums[n], sum[n + 1];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

    sum[0] = 0;
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + nums[i];
    }

    int l, r; // 求 nums[l:r]区间和
    scanf("%d %d", &l, &r);
    printf("%d\n", sum[r] - sum[l - 1]);
    return 0;
}