/**
 * 有n个物品，每个物品的体积分别是volume1，volume2……volumen，
 * 从这些物品中选择一些，使总体积是40，共有多少种不同的选择物品的方式？
 */

#include <cstdio>
#include <iostream>
using namespace std;

// 时间复杂度 O(n*m), m = 40常数
int ways(int nums[], int n, int target) {
	int dp[target + 1];
	dp[0] = 1;
	for (int i = 1; i <= target; i++) dp[i] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = target; j >= nums[i]; j--) {
			dp[j] += dp[j - nums[i]]; // 滚动数组 或 根据状态依赖调整迭代/循环的方向
		}
	}
	return dp[target];
}


int main() {
	int n;
	scanf("%d", &n);
	int volumes[n];
	for (int i = 0; i < n; i++) scanf("%d", &volumes[i]);
	printf("%d", ways(volumes, n, 40));
	return 0;
}
