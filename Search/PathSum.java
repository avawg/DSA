public class PathSum {
    /**
    给你二叉树的根节点 root 和一个表示目标和的整数 targetSum ，
    判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum
    */

    // 时间复杂度 O(n)，其中 n 是树的节点数
    private boolean dfs(TreeNode node, int sum, int targetSum) {
        if (node == null) return false;
        // 访问到叶子节点
        if (node.left == null && node.right == null) {
            return targetSum == sum + node.val;
        }
        boolean left = dfs(node.left, sum + node.val, targetSum);
        if (left) return true;
        boolean right = dfs(node.right, sum + node.val, targetSum);
        if (right) return true;
        return false;
    }

    public boolean hasPathSum(TreeNode root, int targetSum) {
        return dfs(root, 0, targetSum);
    }
}