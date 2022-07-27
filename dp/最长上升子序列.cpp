#include <iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int nums[n], dp[n];
    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
	// O(n * n)
    dp[0] = 1;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}