/**
 * 有一个长度为整数L(1<=L<=10000)的马路，可以想象成数轴上长度为L的一个线段，
 * 起点是坐标原点，在每个整数坐标点有一棵树，即在0,1,2，...，L共L+1个位置上有L+1棵树。
 * 现在要移走一些树，移走的树的区间用一对数字表示，如 100 200表示移走从100到200之间（包括端点）所有的树。
 * 可能有M(1<=M<=100)个区间，区间之间可能有重叠。现在要求移走所有区间的树之后剩下的树的个数。
*/
#include <stdio.h>
#include <stdbool.h>

#define MAXL 20010
int tree[MAXL];
bool marks[MAXL] = {false};

// 建立线段树
void build(int p, int l, int r) {
    if (l == r) {
      tree[p] = 1;
      return ;
    }
    int mid = (l + r) / 2;
    build(2 * p + 1, l, mid);
    build(2 * p + 2, mid + 1, r);
    tree[p] = tree[p * 2 + 1] + tree[p * 2 + 2];
}

void pushDown(int p) {
    marks[p * 2 + 1] = true; // 标记向下传递
    marks[p * 2 + 2] = true;
    tree[p * 2 + 1] = 0; // 往下更新一层
    tree[p * 2 + 2] = 0;
    marks[p] = false; // 清除标记
}
 
// [L, R] 是待更新区间,  [start, end]是在线段树上递归区间
void update(int L, int R, int p, int start, int end) {
    
    if (start > R || end < L) 
        return ;
    if (start >= L && end <= R) { 
        tree[p] = 0;
        marks[p] = true;
        return ;
    }
    if (start != end && marks[p] == true) { // 更新懒节点标记
        pushDown(p);
    }
    int mid = (start + end) / 2;
    update(L, R, p * 2 + 1, start, mid); // 递归地往下寻找
    update(L, R, p * 2 + 2, mid + 1, end);
    tree[p] = tree[p * 2 + 1] + tree[p * 2 + 2]; // 根据子节点更新当前节点的值
}

int query(int L, int R, int p, int start, int end) {
    if (start > R || end < L) 
        return 0;
    if (start >= L && end <= R) {
        return tree[p];
    }
    if (start != end && marks[p] == true) { // 更新懒节点标记
        pushDown(p);
    }
    int mid = (start + end) / 2;
    return query(L, R, p * 2 + 1, start, mid) + query(L, R, p * 2 + 2, mid + 1, end);
}

int main() {
    int l, m;
    scanf("%d %d", &l, &m);
    build(0, 0, l);
    int s, t; // 区间起始点
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &s, &t);
        update(s, t, 0, 0, l);
    }
    printf("%d", tree[0]);
    return 0;
}