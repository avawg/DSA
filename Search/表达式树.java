/**
 * 将给定的表达式树（二叉树）转换为等价的中缀表达式（通过括号反映操作符的计算次序）并输出.
 * Definition for a binary tree node.
 * public class TreeNode {
 *     String val;
 *     TreeNode left;
 *     TreeNode right;
 * }
 */


class Solution {

    public String expressionTree(TreeNode root) {
        StringBuilder s = new StringBuilder();
        dfs(root, root, s);
        return s.toString();
    }

    // 中序遍历二叉树
    void dfs(TreeNode p, TreeNode root, StringBuilder s) {
        if (p.left == null && p.right == null) {
            s.append(p.val);
            return ;
        }

        if (p != root) {
            s.append('(');
        }
        if (p.left != null) {
            dfs(p.left, root, s);
        }
        s.append(p.val);
        if (p.right != null) {
            dfs(p.right, root, s);
        }
        if (p != root) {
            s.append(')');
        }
    }
}