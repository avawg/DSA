#include <iostream>
using namespace std;

const int N = 100010;
int tree[N], nums[N], n;

int lowBit(int x) {
    return x & (-x);
}

// 单点修改 增加值u
void update(int x, int u) {
    for (int i = x; i <= n; i += lowBit(i)) tree[i] += u;
}

// 求前x项和
private int query(int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= lowBit(i)) ans += tree[i];
    return ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
        update(i + 1, nums[i]);
    }
    int l, r;
    scanf("%d %d", &l, &r);
    puts(query(r + 1) - query(l));
    return 0;
}