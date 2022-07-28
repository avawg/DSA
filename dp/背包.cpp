#include <iostream>
using namespace std;

const int N = 1000010;
int v[1010], w[1010], dp[N];

int main() {
    int n, V;
    scanf("%d %d", &n, &V);
    for (int i = 0; i < n; i++) scanf("%d %d", &v[i], &w[i]);

    for (int i = 0; i < n; i++) {
        for (int j = V; j >= v[i]; j--) {
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
        }
    }
    cout << dp[V];
}