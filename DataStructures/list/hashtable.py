# 定义链表
class LinkedList:
    class Node:
        def __init__(self, val=None):
            self.val = val
            self.next = None

    class LinkedListIterator:
        def __init__(self, node):
            self.node = node

        def __next__(self):  # 定义迭代器，调用next返回当前节点值
            if self.node:
                cur_node = self.node
                self.node = cur_node.next
                return cur_node.val
            else:
                raise StopIteration

    def __init__(self, iterable=None):
        self.head = None
        self.tail = None
        if iterable:
            self.extend(iterable)

    def append(self, val):
        node = LinkedList.Node(val)
        # 若链表为空，头尾指针都指向node
        if not self.head:
            self.head = node
            self.tail = node
        # 否则，添加到尾部
        else:
            self.tail.next = node
            self.tail = node

    # 添加列表多个元素
    def extend(self, iterable):
        for val in iterable:
            self.append(val)

    def find(self, val):
        for node in self:
            if node.val == val:
                return True
        return False

    def __iter__(self):  # 让链表支持迭代，for循环
        return self.LinkedListIterator(self.head)

    def __repr__(self):
        return "[" + ", ".join(map(str, self)) + "]"


list = LinkedList([1, 2, 3, 4, 5])
for node in list:
    print(node)
print(list)


# 定义哈希表
class HashTable:
    def __init__(self, capacity=100):
        self.capacity = capacity
        self.table = [LinkedList() for _ in range(capacity)]  # 链表解决冲突

    def insert(self, val):  # 时间复杂度O(1)
        id = val % self.capacity  # hash func 取模运算
        if not self.table[id].find(val):
            self.table[id].append(val)
        else:
            print("重复的插入")

map = HashTable()
map.insert(100)
