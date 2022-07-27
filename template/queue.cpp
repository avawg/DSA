#include <iostream>
using namespace std;

const int N = 100010;
int que[N], hh = 0, tt = -1;

int main() {
    int m;
    scanf("%d", &m);
    string s;
    for (int i = 0; i < m; i++) {
        cin >> s;
        if (s == "push") {
            scanf("%d", &que[++tt]);
        } else if (s == "pop") {
            hh++;
        } else if (s == "empty") {
            cout << (hh <= tt ? "NO" : "YES") << '\n';
        } else {
            printf("%d\n", que[hh]);
        }
    }
    return 0;
}