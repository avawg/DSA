/**
 * 二叉树的带权路径长度(WPL)是二叉树中所有叶结点的带权路径长度之和，也就是每个叶结点的深度与权值之积的总和。
 * 给定一棵二叉树T，请你计算并输出它的 WPL。注意，根节点的深度为 0
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int pathSum(TreeNode root) {
        return dfs(root, 0);
    }

    // 时间复杂度O(logn)
    int dfs(TreeNode p, int depth) {
        if (p == null) {
            return 0;
        }
        if (p.left == null && p.right == null) {
            return p.val * depth;
        }
        int sum = 0;
        if (p.left != null) {
            sum += dfs(p.left, depth + 1);
        }
        if (p.right != null) {
            sum += dfs(p.right, depth + 1);
        }
        return sum;
    }
}