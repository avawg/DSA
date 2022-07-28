#include <iostream>
using namespace std;

int st[100010], tt = 0;

int main() {
    int m;
    scanf("%d", &m);
    string s;
    for (int i = 0; i < m; i++) {
        cin >> s;
        if (s == "push") {
            scanf("%d", &st[++tt]);
        } else if (s == "pop") {
            tt--;
        } else if (s == "empty") {
            cout << (tt > 0 ? "NO" : "YES") << '\n';
        } else {
            printf("%d\n", st[tt]);
        }
    }
    return 0;
}