#include <cstdio>
#include <iostream>
using namespace std;

// 时间复杂度O(n^2)
int longestIncreasingSubsequence(int nums[], int n) {
	int dp[n];
	// dp[i] 表示以nums[i]为终点的最长上升子序列长度
	dp[0] = 1;
	int length = dp[0];
	for (int i = 1; i < n; ++i) {
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {
			if (nums[j] < nums[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		length = max(length, dp[i]);
	}
	return length;
}

int main() {
	int n;
	scanf("%d", &n);
    int nums[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &nums[i]);
	}
	int length = longestIncreasingSubsequence(nums, n);
	printf("%d", length);
}
