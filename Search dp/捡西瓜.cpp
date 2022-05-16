/**
 * n个西瓜排成一列，每个西瓜有两个属性（weight, skip);weight表示西瓜的重量，skip表示捡完该西瓜后，
 * 就必须跳过接下来的skip个西瓜[i + 1, i + skip]，即不能捡起它们。
 * 经过每个西瓜的必须选择捡或不捡，不能回头；输出能捡起西瓜的最大质量
 */
#include <iostream>
using namespace std;

int ans = 0;
const int MAX = 100001;
int weight[MAX], skip[MAX];
int dp[MAX];

void dfs(int i, int n, int score);

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> skip[i];
    }
    for (int i = 0; i < n; i++) {
        dp[i] = -1;
    }
    dfs(0, n, 0);
    cout << ans;
    return 0;
}

// dp 记忆化搜索
// dp[i]表示前0-i个西瓜能获得的最大质量
void dfs(int i, int n, int score) {
	if (i >= n) {
		ans = score > ans ? score : ans;
		return ;
	}
	if (score <= dp[i]) {
		return ;
	} else {
		dp[i] = score;
	}
	// 捡第i个西瓜
	dfs(i + skip[i] + 1, n, score + weight[i]);
	// 不捡第i个西瓜
	dfs(i + 1, n, score);
}
