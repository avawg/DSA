class SegmentTree {

    class Node {
        Node left, right;
        int height;
        boolean flag;
    }

    Node root = new Node();

    public int query(int l, int r, Node node, int s, int e) {
        if (s <= l && r <= e) {
            return node.height;
        }
        lazyCreate(node);
        if (node.flag) pushDown(node);
        int mid = (l + r) / 2;
        int h = 0;
        if (mid >= s) h = Math.max(h, query(l, mid, node.left, s, e));
        if (mid + 1 <= e) h = Math.max(h, query(mid + 1, r, node.right, s, e));

        return h;
    }

    public void update(int l, int r, Node node, int s, int e, int h) {
        if (s <= l && r <= e) {
            node.height = h;
            node.flag = true;
            return ;
        }
        lazyCreate(node);
        if (node.flag) pushDown(node);
        int mid = (l + r) / 2;
        if (mid >= s) update(l, mid, node.left, s, e, h);
        if (mid + 1 <= e) update(mid + 1, r, node.right, s, e, h);
        pushUp(node);
    }

    private void lazyCreate(Node node) {
        if (node.left == null) node.left = new Node();
        if (node.right == null) node.right = new Node();
    }

    private void pushDown(Node node) {
        node.left.height = node.right.height = node.height;
        node.left.flag = node.right.flag = true;
        node.flag = false;
    }

    private void pushUp(Node node) {
        node.height = Math.max(node.left.height, node.right.height);
    }
}