#include <iostream>
using namespace std;

const int N = 100003;
int e[N], ne[N], h[N], idx;

void insert(int x) {
    int k = (x % N + N) % N;
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool find(int x) {
    int k = (x % N + N) % N;
    for (int i = h[k]; i != -1; i = ne[i]) {
        if (e[i] == x) return true;
    }
    return false;
}

int main() {
    int n, x;
    char c;
    scanf("%d\n", &n);
    for (int i = 0; i < N; i++) h[i] = -1;
    for (int i = 0; i < n; i++) {
        scanf("%c %d\n", &c, &x);
        if (c == 'I') {
            insert(x);
        } else {
            printf(find(x) ? "Yes\n" : "No\n");
        }
    }
    return 0;
}