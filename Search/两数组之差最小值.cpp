#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * 一个数组中有若干正整数，将此数组划分为两个子数组，使得两个子数组各元素之和a,b的差最小，对于非法输入应该输出ERROR。
  设两个子数组的元素和分别为 sum1, sum2，数组的元素和为sum，则：
  sum = sum1 + sum2
  sum1 - sum2 = sum - 2 * sum2 >= 0, s.t. sum1 >= sum2
  sum2 <= (sum / 2)
 */

// 从数组nums选出一组元素，和能为小于n的最大值，dfs
int res = 0;
void dfs(vector<int> &nums, int id, int sum, int maxSum) {
  if (sum == maxSum || id == nums.size()) {
    res = max(res, sum);
    return ;
  }
  for (int i = id; i < nums.size(); i++) {
    if (sum + nums[i] > maxSum) { // 剪枝
      break;
    }
    dfs(nums, i + 1, sum + nums[i], maxSum);
  }
}

int main() {
  string s;
  while (getline(cin, s)) {
    // 将输入的每行数据转化为数组，并判断是否合法
    int i = 0;
    bool legal = true;
    vector<int> nums;
    while (s[i]) {
      if (s[i] == ' ') {
        while (s[i] == ' ') i++;
      } else if (s[i] >= '0' && s[i] <= '9') {
        int val = 0;
        while (s[i] >= '0' && s[i] <= '9') {
          val = val * 10 + s[i] - '0';
          i++;
        }
        nums.push_back(val);
      } else {
        legal = false;
        break;
      }  
    }
    // 不合法
    if (legal == false) {
      printf("ERROR\n");
      continue;
    }
    int sum = 0;
    for (auto num : nums) {
      sum += num;
    }
    sort(nums.begin(), nums.end());
    int maxSum = sum / 2;
    res = 0;
    dfs(nums, 0, 0, maxSum);
    printf("%d %d\n", sum - res, res);
  }
}