#include <iostream>
#include <cstdlib>
#include <set>
#include <queue>
using namespace std;

/*
八数码问题也称为九宫问题。在3×3的棋盘，摆有八个棋子，每个棋子上标有1至8的某一数字，不同棋子上标的数字不相同。
棋盘上还有一个空格，与空格相邻的棋子可以移到空格中。
要求解决的问题是：给出一个初始状态和一个目标状态，找出一种从初始转变成目标状态的移动棋子步数最少的移动步骤。
所谓问题的一个状态就是棋子在棋盘上的一种摆法。棋子移动后，状态就会发生改变。
*/

char dir[5] = "udlr"; // 四种移动方向：向上，向下，向左，向右。

// 广度优先搜索，记录下每步的状态（用数字表示），以及到该步所走的路径
// 时间复杂度 o(n + m) n = 9!, m = 4 * 9!
struct Step {
    int x;
    string path;
    Step(int x, string p): x(x), path(p) {}
};

// 求当前状态（x表示）下，空格向i方向移动后，形成的新的状态（数字）
int convert(int x, int i) {
    char s[10];
    int k = 8;
    while (x) {
        s[k--] = x % 10 + '0';
        x /= 10;
    }
    s[9] = '\0';  // char c = 0 和char c = '\0'相同
    for (k = 0; k < 9; ++k)
        if (s[k] == '9') break;  // 找到空格位置（k）
    switch (i) {
        case 0:                                       // 向上移动
            if (k > 2) swap(s[k], s[k-3]);
            break;
        case 1:                                       // 向下移动
            if (k < 6) swap(s[k], s[k+3]);
            break;
        case 2:                                       // 向左移动，不能是0，3，6
            if (k % 3) swap(s[k], s[k-1]);
            break;
        case 3:                                       // 向右移动，不能是2，5，8
            if ((k + 1) % 3) swap(s[k], s[k+1]);
            break;
    }
    return atoi(s);
}

string bfs(char s[]) {
    queue<Step> q;
    q.push(Step(atoi(s), ""));
    // 记录初始状态
    set<int> visited;
    visited.insert(atoi(s));
    while (!q.empty()) {
        Step cur = q.front();
        q.pop();
        if (cur.x == 123456789) {  // 如果已经走到目标状态‘12345678 ’，则输出路径，退出。
            return cur.path;
        }
        for (int i = 0; i < 4; ++i) {  // 遍历四种移动方法
            int x = convert(cur.x, i);
            if (visited.find(x) == visited.end()) { // 该状态未被访问到
                q.push(Step(x, cur.path + dir[i]));
                visited.insert(x);
            }
        }
    }
    return "unsolvable";
}

int main() {
    char s[10];
    // 读入初始状态
    for (int i = 0; i < 9; ++i) {
        cin >> s[i];
        if (s[i] == 'x')    s[i] = '9'; // 'x'代表空格，将相应位置数字设为9
    }
    s[9] = '\0';
    string ret = bfs(s);
    cout << ret;
    return 0;
}
