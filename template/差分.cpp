#include <iostream>
#include <cstring>
using namespace std;

int dif[100010];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    memset(dif, 0, sizeof(dif));

    int l, r, c;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &l, &r, &c);
        dif[l] += c;
        dif[r + 1] -= c;
    }

    int nums[n];
    nums[0] = dif[0];
    for (int i = 1; i < n; i++) {
        nums[i] = nums[i - 1] + dif[i]; // 前缀和
    }
    return 0;
}