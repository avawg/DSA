/**
 * 线段树求区间和，更改区间和
 */
class SegmentTree {

    class Node {
        Node left, right;
        int sum;
        boolean flag; // 懒标记
    }

    Node root = new Node();

    public int query(Node node, int l, int r, int s, int e) {
        if (s <= l && r <= e) {
            return node.sum;
        }
        lazyCreate(node);
        if (node.flag) pushDown(node, l, r);
        int mid = (l + r) >> 1;
        int sum = 0;
        if (mid >= s) sum += query(node.left, l, mid, s, e);
        if (mid + 1 <= e) sum += query(node.right, mid + 1, r, s, e);
        return sum;
    }

    public void update(Node node, int l, int r, int s, int e) {
        if (s <= l && r <= e) {
            node.sum = r - l + 1;
            node.flag = true;
            return ;
        }
        lazyCreate(node);
        if (node.flag) pushDown(node, l, r);
        int mid = (l + r) >> 1;
        if (mid >= s) update(node.left, l, mid, s, e);
        if (mid < e) update(node.right, mid + 1, r, s, e);
    }

    private void lazyCreate(Node node) {
        if (node.left == null) node.left = new Node();
        if (node.right == null) node.right = new Node();
    }

    private void pushDown(Node node, int l, int r) {
        int mid = (l + r) >> 1;
        node.left.sum = mid - l + 1;
        node.right.sum = r - mid;
        node.left.flag = node.right.flag = true;
        node.flag = false;
    }
}