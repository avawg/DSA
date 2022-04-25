class BinaryIndexedTree {

    // 二叉索引树(binary indexed tree)即树状数组实现，单点修改和区间和查询时间复杂度都为O(logn)
    // tree[i] 以下标i为终点的前lowBit(i)项的和
    int[] tree;
    int[] nums;
    int n;

    public BinaryIndexedTree(int[] nums) {
        this.nums = nums;
        n = nums.length;
        tree = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            add(i + 1, nums[i]);
        }
    }

    private int lowBit(int x) {
        return x & (-x);
    }

     // 求前x项和，时间复杂度O(logn)
    private int query(int x) {
        int ans = 0;
        // i -= lowBit(i) 到左侧的父节点
        for (int i = x; i > 0; i -= lowBit(i)) ans += tree[i];
        return ans;
    }

    // 单点修改 增加值u，时间复杂度O(logn)
    private void add(int x, int u) {
        for (int i = x; i <= n; i += lowBit(i)) tree[i] += u;
    }

    public void update(int i, int val) {
        add(i + 1, val - nums[i]);
        nums[i] = val;
    }

    public int sumRange(int l, int r) {
        return query(r + 1) - query(l);
    }

    public static void main(String[] args) {
        int[] nums = {1, 3, 5};
        BinaryIndexedTree tree = new BinaryIndexedTree(nums);
        System.out.println(tree.sumRange(0, 2));
        tree.update(2, 10);
        System.out.println(tree.sumRange(0, 2));
    }
}