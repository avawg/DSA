/**
 * 给定一个单链表的头节点  head ，其中的元素 按升序排序 ，将其转换为高度平衡的二叉搜索树。
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差不超过 1。
 */

 /**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    ListNode p = null;
    public TreeNode sortedListToBST(ListNode head) {
        // 链表长度
        p = head;
        int length = 0;
        while (p != null) {
            length++;
            p = p.next;
        }
        p = head;
        TreeNode root = build(0, length - 1);
        return root;
    }

    // 模拟中序遍历
    TreeNode build(int l, int r) {
        if (l > r) {
            return null;
        }
        int m = l + (r - l + 1) / 2;
        TreeNode node = new TreeNode();
        node.left = build(l, m - 1);
        node.val = p.val;
        p = p.next;
        node.right = build(m + 1, r);
        return node;
    }
}
