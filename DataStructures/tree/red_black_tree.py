from binary_search_tree import TreeNode, BinarySearchTree

Red = False
Black = True

class RedBlackTreeNode(TreeNode):
    def __init__(self, val):
        TreeNode.__init__(self, val)
        self.color = Red

class RedBlackTree(BinarySearchTree):

    def __init__(self, nums=None):
        BinarySearchTree.__init__(self, nums)

    def insert(self, val):
        node = RedBlackTreeNode(val)
        node = self._insertNode(node)  # 插入成功返回node, 否则值重复返回None
        if node is None:
            return
        else:
            self.__fixAfterInsert(node)  # 从插入节点开始调整

    def _removeNode(self, node):
        replacement = node.left if node.left is not None else node.right
        # 替代节点不为空
        if replacement is not None:
            self._removeNonLeafNode(node, replacement)
            # 此时 node 是黑色, 替代节点是红色，此时只需变色
            replacement.color = Black

        # node节点是叶子节点
        else:
            # 黑色先调整
            if node.color == Black:
                self.__fixBeforeRemove(node)
            self._removeLeafNode(node)

    def __fixAfterInsert(self, node):
        """
        1、2-3-4树：新增元素节点 1个元素 -> 2个元素 上黑下红 无须调整
        2、2-3-4树：新增元素节点 2个元素 -> 3个元素
                    4种小情况(左3，右3)，左中右(node.parent.color = Black)不需调整 => 中间节点是黑色，两边节点都是红色
        3、2-3-4树：新增元素节点 3个元素 -> 4个元素  4节点分裂，中间元素升级为父节点，新增元素与剩下的其中一个合并
                   爷爷节点变红，父亲和叔叔变黑，如果爷爷是根节点，则再变黑
        """
        node.color = Red
        while node is not self.root and node.parent.color == Red:
            grand_parent = node.parent.parent
            parent = node.parent
            # node的父节点是爷爷的左孩子
            if parent == grand_parent.left:
                # 叔叔节点
                uncle = grand_parent.right
                if self.__colorOf(uncle) == Red:  # 插入到3节点 分裂
                    parent.color = Black
                    uncle.color = Black
                    grand_parent.color = Red
                    node = grand_parent  # 爷爷节点递归
                else:  # 插入到2节点 调整
                    if node == parent.right:
                        node = parent
                        self._leftRotate(node)
                    parent.color = Black  # 父亲变黑
                    grand_parent = Red  # 爷爷变红
                    # 右旋 红(node) 黑(node.parent) 红 三元素节点 退出循环
                    self._rightRotate(grand_parent)
            else:
                uncle = grand_parent.left
                if self.__colorOf(uncle) == Red:  # 插入到3节点 分裂
                    parent.color = Black
                    uncle.color = Black
                    grand_parent.color = Red
                    node = grand_parent
                else:  # 插入到2节点 调整
                    if node == parent.left:
                        node = parent
                        self._rightRotate(node)
                    parent.color = Black  # 父亲变黑
                    grand_parent.color = Red  # 爷爷变红
                    # 左旋 红 黑(node.parent) 红(node) 三元素节点 退出循环
                    self._leftRotate(grand_parent)
        self.root.color = Black

    # 删除前调整
    def __fixBeforeRemove(self, node):
        parent = node.parent
        while node is not self.root and node.color == Black:
            # node是左孩子的情况:
            if node is parent.left:
                # 兄弟节点
                sibling = parent.right
                # 判断此时兄弟节点是否是真正的兄弟节点，还是父亲节点
                if sibling.color == Red:
                    sibling.color = Black
                    parent.color = Red
                    self._leftRotate(parent)
                    # 找到真正的兄弟节点, 二个元素节点右倾变左倾
                    sibling = parent.right

                # 找兄弟借，兄弟节点只有一个元素
                if self.__colorOf(sibling.left) == Black and self.__colorOf(sibling.right) == Black:
                    sibling.color = Red  # 将兄弟节点和父节点合并
                    node = parent

                # 找兄弟借，兄弟有的借
                else:
                    if self.__colorOf(sibling.right) == Black:
                        sibling.left = Black
                        sibling.color = Red
                        self._rightRotate(sibling)
                        sibling = parent.right
                    sibling.color = parent.color  # 兄弟节点向上
                    parent.color = Black  # 父节点向下
                    sibling.right.color = Black
                    self._leftRotate(parent)
                    node = self.root  # 借到节点, 退出

            # node是右孩子的情况, 和左孩子相反
            else:
                # 兄弟节点
                sibling = parent.left
                # 判断此时兄弟节点是否是真正的兄弟节点，还是父亲节点
                if sibling.color == Red:
                    sibling.color = Black
                    parent.color = Red
                    self._rightRotate(parent)
                    # 找到真正的兄弟节点, 二个元素节点左倾变右倾
                    sibling = parent.left

                # 找兄弟借，兄弟节点只有一个元素
                if self.__colorOf(sibling.left) == Black and self.__colorOf(sibling.right) == Black:
                    sibling.color = Red  # 将兄弟节点和父节点合并
                    node = parent
                # 找兄弟借，兄弟有的借
                else:
                    if self.__colorOf(sibling.left) == Black:
                        sibling.right = Black
                        sibling.color = Red
                        self._leftRotate(sibling)
                        sibling = parent.left
                    sibling.color = parent.color  # 兄弟节点向上
                    parent.color = Black  # 父节点向下
                    sibling.left.color = Black
                    self._rightRotate(parent)
                    node = self.root  # 借到节点, 退出

        # 红(父） 黑(子) 将父亲染成黑色 合并成功返回
        # 合并到根节点，空一节点，2-3-4树高度减1
        node.color = Black

    @staticmethod
    def __colorOf(node):
        return node.color if node is not None else Black


if __name__ == "__main__":
    tree = RedBlackTree()
    for i in range(1, 10):
        tree.insert(i)
        print("after insert %d:" % i)
        tree.draw()
    tree.remove(8)
    print("after remove 8:")
    tree.draw()