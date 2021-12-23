class BinaryIndexedTree {

    // 二叉索引树(binary indexed tree)即树状数组实现，单点修改和区间和查询时间复杂度都为O(logn)
    // tree[i] 以下标i为终点的lowBit(i)项的和
    private int[] tree;

    public BinaryIndexedTree(int[] nums) {
        tree = new int[nums.length + 1];
        for (int i = 0; i < nums.length; ++i) {
            update(i, nums[i]);
        }
    }

    // 单点修改 x增加值，时间复杂度O(logn)
    public void update(int i, int x) {
        ++i;
        while (i < tree.length) {
            tree[i] += x;
            i += lowBit(i); // 转到父节点
        }
    }

    public int sumRange(int l, int r) {
        return query(r) - query(l - 1);
    }

    // 求[0, n]前n项和，时间复杂度O(logn)
    private int query(int n) {
        int res = 0;
        // i -= lowBit(i) 到左侧的父节点
        for (int i = n + 1; i > 0; i -= lowBit(i)) {
            res += tree[i];
        }
        return res;
    }

    private int lowBit(int x) {
        return x & (-x);
    }

    public static void main(String[] args) {
        int[] nums = {1, 3, 5};
        BinaryIndexedTree tree = new BinaryIndexedTree(nums);
        System.out.println(tree.sumRange(0, 2));
        tree.update(2, 10);
        System.out.println(tree.sumRange(0, 2));
    }
}