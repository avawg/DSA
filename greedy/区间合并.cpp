#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    pair<int, int> nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &nums[i].first, &nums[i].second);
    }
    sort(nums, nums + n);
    int r = nums[0].second, ans = 1;
    for (int i = 1; i < n; i++) {
        if (nums[i].first <= r) {
            r = max(r, nums[i].second);
        } else {
            r = nums[i].second;
            ans++;
        }
    }
    cout << ans;
    return 0;
}