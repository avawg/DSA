#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int bfs(string s) {
    queue<string> q;
    q.push(s);
    unordered_map<string, int> d;
    d[s] = 0;

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    while (!q.empty()) {
        string t = q.front();
        q.pop();

        if (t == "12345678x") return d[t];
        int k = t.find('x');
        int r = k / 3, c = k % 3, dis = d[t];
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i], nc = c + dy[i];
            if (nr >= 0 && nr < 3 && nc >= 0 && nc < 3) {
                swap(t[k], t[nr * 3 + nc]);
                if (!d.count(t)) {
                    q.push(t);
                    d[t] = dis + 1;
                }
                swap(t[k], t[nr * 3 + nc]);
            }
        }
    }
    return -1;
}

int main() {
    string s = "";
    char c;
    for (int i = 0; i < 9; i++) {
        cin >> c;
        s += c;
    }
    cout << bfs(s);
}