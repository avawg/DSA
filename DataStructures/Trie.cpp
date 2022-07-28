// 字典树 存储查询字符串
#include <iostream>
using namespace std;

const int N = 100010;
int son[N][26], cnt[N], idx;

void insert(string s) {
    int p = 0;
    for (auto& c : s) {
        if (!son[p][c - 'a']) {
            son[p][c - 'a'] = ++idx;
        }
        p = son[p][c - 'a'];
    }
    cnt[p]++;
}

int query(string s) {
    int p = 0;
    for (auto& c : s) {
        if (!son[p][c - 'a']) return 0;
        p = son[p][c - 'a'];
    }
    return cnt[p];
}

int main() {
    int n;
    scanf("%d", &n);
    char c;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> c >> s;
        if (c == 'I') insert(s);
        else cout << query(s) << endl;
    }
    return 0;
}