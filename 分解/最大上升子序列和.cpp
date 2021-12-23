#include <cstdio>
#include <iostream>
using namespace std;

// 时间复杂度O(n^2)
int maxSequenceSum(int nums[], int n) {
	int dp[n];
	// dp[i] 表示以i为终点的最大上升序列和
	dp[0] = nums[0];
	int ret = dp[0];
	for (int i = 1; i < n; ++i) {
		dp[i] = nums[i];
		for (int j = 0; j < i; ++j) {
			if (nums[j] < nums[i]) {
				dp[i] = max(dp[i], dp[j] + nums[i]);
			}
		}
		ret = max(ret, dp[i]);
	}
	return ret;
}

int main() {
	int n;
	scanf("%d", &n);
    int nums[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &nums[i]);
	}
	int ret = maxSequenceSum(nums, n);
	printf("%d", ret);
	return 0;
}