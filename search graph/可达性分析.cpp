#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
/**

*/

vector<vector<int>> g;
unordered_set<int> roots;
unordered_set<int> st;

void dfs(int u) {
    for (auto v : g[u]) {
        if (!st.count(v)) {
            st.insert(v);
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a;
        while (a --) {
            cin >> b;
            g[i].push_back(b);
        }
    }

    int res = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a == 1) roots.insert(b);
        else roots.erase(b);

        st.clear();
        for (auto x : roots) {
            st.insert(x);
            dfs(x);
        }
        res = max(res, (int)st.size());
    }
    cout << res;
}
