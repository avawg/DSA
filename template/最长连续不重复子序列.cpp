#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; i++) cin >> nums[i];

    unordered_set<int> set;
    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        // template
        while (j <= i && set.count(nums[i])) {
            set.erase(nums[j++]);
        }
        set.insert(nums[i]);
        ans = max(ans, i - j + 1);
    }
    cout << ans;
    return 0;
}