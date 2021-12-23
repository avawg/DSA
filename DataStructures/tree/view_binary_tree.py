import queue

null = "null"

# 仿照LeetCode 给定数组进行树结构可视化

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

# 利用字符数组绘制树
def draw(root):
    if root is None:
        return
    treeDepth = getTreeDepth(root)
    height = treeDepth * 2 - 1
    width = treeDepth * (treeDepth - 1) * 2 + 1
    array = [[' ' for _ in range(width)] for _ in range(height)]
    writeArray(root, array, 0, width // 2, 1, treeDepth)
    for i in range(height):
        line = ""
        length = 0
        for j in range(width):
            length += len(array[i][j]) - 9 if len(array[i][j]) > 9 else len(array[i][j])
            # 9是格式颜色字符串长度
            if length > j + 1 and array[i][j] == ' ':
                length -= 1
                continue
            line += array[i][j]
        print(line)

# 将树信息写入数组array中
def writeArray(node, array, row, col, depth, treeDepth):
    if node is None:
        return
    if hasattr(node, "color"): # 是否有颜色
        if not node.color:
            array[row][col] = "\033[31m%s\033[0m" % node.val
        else:
            array[row][col] = "\033[30m%s\033[0m" % node.val
    else:
        array[row][col] = str(node.val)
    if depth == treeDepth:
        return
    # 计算当前行到下一行，每个元素之间的间隔（下一行的列索引与当前元素的列索引之间的间隔）
    gap = treeDepth - depth

    # 递归左右孩子填充
    if node.left is not None:
        array[row + 1][col - gap] = '/'
        writeArray(node.left, array, row + 2, col - gap * 2, depth + 1, treeDepth)
    if node.right is not None:
        array[row + 1][col + gap] = '\\'
        writeArray(node.right, array, row + 2, col + gap * 2, depth + 1, treeDepth)

# 树高
def getTreeDepth(node):
    return 0 if node is None else 1 + max(getTreeDepth(node.left), getTreeDepth(node.right))

# 从nums数组中构建树
def constructTree(nums):
    if len(nums) == 0:
        return None
    root = TreeNode(nums[0])
    idx = 0
    que = queue.Queue()
    que.put(root)
    while not que.empty():
        node = que.get()
        idx += 1
        if idx < len(nums):
            node.left = None if nums[idx] == null else TreeNode(nums[idx])
            if node.left:
                que.put(node.left)
        else:
            break
        idx += 1
        if idx < len(nums):
            node.right = None if nums[idx] == null else TreeNode(nums[idx])
            if node.right:
                que.put(node.right)
        else:
            break
    return root

def main():
    nums = [3, 1, 4, 3, null, 1, 5]
    tree = constructTree(nums)
    draw(tree)

if __name__ == "__main__":
    main()