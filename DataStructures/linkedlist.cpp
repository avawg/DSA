#include <iostream>
using namespace std;

const int N = 100010;
int head, e[N], ne[N], idx;

void init() {
    head = -1;
    idx = 0;
}

void add_to_head(int x) {
    e[idx] = x; ne[idx] = head; head = idx++;
}

int main() {
    init();
    int m, x;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        add_to_head(x);
    }
    for (int i = head; i != -1; i = ne[i]) printf("%d ", e[i]);
    return 0;
}