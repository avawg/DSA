#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int t; cin >> t;

    // 第一次必定抽到
    int cnt = 0, res = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == t) {
            ++cnt;
            if (rand() % cnt == 0) {
                res = i;
            }
        }
    }
    cout << res;
    return 0;
}