/**
 * n个西瓜排成一列，每个西瓜有两个属性（weight, skip);weight表示西瓜的重量，skip表示捡完；
 * 该西瓜后，就必须跳过接下来的skip个西瓜[i + 1, i + skip]，即不能捡起它们。
 * 经过每个西瓜的必须选择捡或不捡，不能回头；输出能捡起西瓜的最大质量
 */
#include <iostream>
using namespace std;

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
        dp[i] = 0;
    }
    dfs(0, n, 0);
    cout << dp[n - 1];
    return 0;
}

// dp 记忆化搜索
// dp[i]表示前0-i个西瓜能获得的最大质量
void dfs(int i, int n, int score) {
	if (i >= n) {
		return ;
	}
	// 捡第i个西瓜
	int end = min(n - 1, i + skip[i]);
	if (score + weight[i] >= dp[end]) {
		dp[end] = score + weight[i];
		dfs(end + 1, n, score + weight[i]);
	}
	// 不捡第i个西瓜
	if (score >= dp[i]) {
		dp[i] = score;
		dfs(i + 1, n, score);
	}
}
