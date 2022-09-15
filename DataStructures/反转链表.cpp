#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int d): data(d), next(nullptr){}
};

int main() {
    int n;
    cin >> n;

    ListNode * head = new ListNode(-1), *tail = head;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ListNode* p = new ListNode(x);

        tail->next = p;
        tail = p;
    }

    // 反转l 到 r之间的链表
    int l, r;
    cin >> l >> r;
    ListNode * p = head;
    // 第l个节点的前驱节点
    for (int i = 1; i < l; i++) p = p->next;

    ListNode* h = p, *t = p->next;
    p = p->next;
    for (int i = l; i <= r; i++) {
        ListNode* rr = p->next;
        p->next = h->next;
        h->next = p;
        p = rr;
    }
    t->next = p;

    p = head->next;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->next;
    }
}
