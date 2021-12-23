from binary_search_tree import TreeNode, BinarySearchTree

class AvlTreeNode(TreeNode):
    def __init__(self, val):
        TreeNode.__init__(self, val)
        self.height = 0  # 节点添加height变量实现平衡二叉树

class AVLTree(BinarySearchTree):

    def __init__(self, nums=None):
        BinarySearchTree.__init__(self, nums)

    def insert(self, val):
        node = AvlTreeNode(val)
        node = self._insertNode(node)  # 插入成功返回node, 否则值重复返回None
        if node is None:
            return
        else:
            node = node.parent
            self.__balance(node)  # 从父节点开始调整

    # 删除node节点，此时node已由后继节点代替
    def _removeNode(self, node):
        parent = node.parent
        super()._removeNode(node)
        self.__balance(parent)  # 从父节点开始调整

    def __balance(self, node):
        while node is not None:
            # 计算平衡因子, 左子树高度减右子树高度
            balance_factor = self.__height(node.left) - self.__height(node.right)
            # 不平衡则调整, 否则更新高度向上传递
            if balance_factor > 1:
                if self.__height(node.left.right) > self.__height(node.left.left):
                    self._leftRotate(node.left)
                    self.__updateHeight(node.left)
                    self.__updateHeight(node.left.left)
                self._rightRotate(node)
                self.__updateHeight(node)
                self.__updateHeight(node.parent)
                break
            elif balance_factor < -1:
                if self.__height(node.right.left) > self.__height(node.right.right):
                    self._rightRotate(node.right)
                    self.__updateHeight(node.right)
                    self.__updateHeight(node.right.right)
                self._leftRotate(node)
                self.__updateHeight(node)
                self.__updateHeight(node.parent)
                break
            else:
                prev_height = node.height
                self.__updateHeight(node)
                if node.height == prev_height:  # 节点高度不变，不再向上传递
                    break
                else:
                    node = node.parent

    @staticmethod
    def __height(node):
        return -1 if node is None else node.height

    def __updateHeight(self, node):
        node.height = max(self.__height(node.left), self.__height(node.right)) + 1


if __name__ == "__main__":
    tree = AVLTree([9, 8, 7, 6, 5, 4, 3, 2, 1])
    tree.draw()
    tree.remove(6)
    print("after remove 6:")
    tree.draw()
    tree.remove(9)
    print("after remove 9:")
    tree.draw()