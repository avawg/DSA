#include <iostream>
using namespace std;

const int N = 100010;
int q[N], hh = 0, tt = -1, cnt;

// 入队
void push(int x) {
    if (cnt != N) {
        tt = (tt + 1) % N;
        q[tt] = x;
        ++cnt;
    }
}

 // 出队
int pop() {
    if (cnt > 0) {
        int x = q[hh];
        hh = (hh + 1) % N;
        --cnt;
        return x;
    }
    return -1;
}

bool empty() {
    return cnt == 0 ?
}

int main() {
    return 0;
}