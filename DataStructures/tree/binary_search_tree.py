from view_binary_tree import draw

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None

class BinarySearchTree:
    """
     二叉查找树 若为平衡二叉树，则find, insert, remove, extract-max, extract-min,
     predecessor, successor时间复杂度都为O(log(n))
    """
    def __init__(self, nums=None):
        self.root = None
        if nums:
            for val in nums:
                self.insert(val)

    def find(self, val):
        node = self._findNode(val)
        return True if node is not None else False

    def insert(self, val):
        node = TreeNode(val)
        self._insertNode(node)

    def remove(self, val):
        node = self._findNode(val)
        if node is None:
            return
        # node有两个孩子节点, 寻找node后继节点rep, 将其值赋给node, 再删除rep, 保持有序
        if node.left is not None and node.right is not None:
            rep = self._successor(node)
            # rep = self._predecessor(node)
            node.val = rep.val
            node = rep
        self._removeNode(node)

    def draw(self):
        draw(self.root)

    def _findNode(self, val):
        node = self.root
        while node is not None:
            cmp = val - node.val
            if cmp < 0:
                node = node.left
            elif cmp > 0:
                node = node.right
            else:
                return node
        return None

    # 节点插入
    def _insertNode(self, node):
        p = self.root
        # 如果是根节点
        if p is None:
            self.root = node
            return self.root
        # 寻找插入位置
        parent = None
        cmp = 0
        while p is not None:
            parent = p
            cmp = node.val - p.val
            if cmp < 0:
                p = p.left
            elif cmp > 0:
                p = p.right
            else:
                return None  # 重复插入
        node.parent = parent
        if cmp < 0:
            parent.left = node
        else:
            parent.right = node
        return node

    # 删除node节点
    def _removeNode(self, node):
        # node是叶子节点 或 只有一个孩子节点, 将孩子直接挂在p的位置
        replacement = node.left if node.left is not None else node.right
        # 替代节点不为空
        if replacement is not None:
            self._removeNonLeafNode(node, replacement)
        # node节点是叶子节点
        else:
            self._removeLeafNode(node)

    def _removeNonLeafNode(self, node, replacement):
        replacement.parent = node.parent
        if node.parent is None:  # node是根节点
            self.root = replacement
        elif node == node.parent.left:
            node.parent.left = replacement
        else:
            node.parent.right = replacement
        # 将node的左右孩子指针和父指针都指向null（此时node处于游离状态，等待垃圾回收）
        node.left = node.right = node.parent = None

    def _removeLeafNode(self, node):
        if node.parent is None:
            self.root = None  # 删除节点是根节点
        elif node == node.parent.left:
            node.parent.left = None
        else:
            node.parent.right = None
        node.parent = None

    def _leftRotate(self, p):  # 左旋
        if p is not None:
            r = p.right
            p.right = r.left
            if r.left is not None:
                r.left.parent = p
            r.parent = p.parent
            if p.parent is None:
                self.root = r
            elif p.parent.left == p:
                p.parent.left = r
            else:
                p.parent.right = r
            r.left = p
            p.parent = r
            return r

    def _rightRotate(self, p):  # 右旋
        if p is not None:
            l = p.left
            p.left = l.right
            if l.right is not None:
                l.right.parent = p
            l.parent = p.parent
            if p.parent is None:
                self.root = l
            elif p.parent.left == p:
                p.parent.left = l
            else:
                p.parent.right = l
            l.right = p
            p.parent = l
            return l

    # 寻找后继节点
    @staticmethod
    def _successor(node):
        if node is None:
            return None
        elif node.right is not None:
            p = node.right
            while p.left is not None:
                p = p.left
        else:
            p = node.parent
            ch = node
            while p is not None and ch == p.right:
                ch = p
                p = p.parent
        return p

    # 寻找前驱节点
    @staticmethod
    def _predecessor(node):
        if node is None:
            return None
        elif node.left is not None:
            p = node.left
            while p.right is not None:
                p = p.right
        else:
            p = node.parent
            ch = node
            while p is not None and ch == p.left:
                ch = p
                p = p.parent
        return p


def main():
    import random
    nums = list(range(0, 20, 2))
    random.shuffle(nums)
    tree = BinarySearchTree(nums)
    tree.draw()
    print(tree.find(16))
    tree.remove(10)
    print("after remove 10:")
    tree.draw()


if __name__ == '__main__':
    main()