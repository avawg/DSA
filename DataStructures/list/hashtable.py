# 用链表来定义哈希表
class LinkList:
    class Node:
        def __init__(self, item=None):
            self.item = item
            self.next = None

    class LinkListIterator:
        def __init__(self, node):
            self.node = node

        def __next__(self):  # 定义迭代器，调用next返回当前节点值
            if self.node:
                cur_node = self.node
                self.node = cur_node.next
                return cur_node.item
            else:
                raise StopIteration

    def __init__(self, iterable=None):
        self.head = None
        self.tail = None
        if iterable:
            self.extend(iterable)

    def append(self, obj):
        s = LinkList.Node(obj)
        # 若链表为空，头尾指针都指向s
        if not self.head:
            self.head = s
            self.tail = s
        # 否则，添加到尾部
        else:
            self.tail.next = s
            self.tail = s

    # 添加列表多个元素
    def extend(self, iterable):
        for obj in iterable:
            self.append(obj)

    def find(self, obj):
        for item in self:
            if item == obj:
                return True
        else:
            return False

    def __iter__(self):  # 让链表支持迭代，for循环
        return self.LinkListIterator(self.head)

    def __repr__(self):
        return "[" + ", ".join(map(str, self)) + "]"


lk = LinkList([1, 2, 3, 4, 5])
for i in lk:
    print(i)
print(lk)


# 定义哈希表
class HashTable:
    def __init__(self, size=100):
        self.size = size
        self.T = [LinkList() for _ in range(size)]  # 链表组成一个数组

    def insert(self, k):  # 时间复杂度O(1)
        i = k % self.size  # 简单的模运算映射，链表解决冲突
        if not self.T[i].find(k):
            self.T[i].append(k)
        else:
            print("重复的插入")