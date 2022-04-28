class CircularQueue2 {

    int[] nums;
    int head, tail;
    int n;

    public CircularQueue2(int k) {
        nums = new int[k + 1]; // 多用一个空间判断是否为满
        n = k + 1;
        head = tail = 0;
    }

    // 入队
    public void offer(int value) {
        if ((tail + 1) % n != head) {
            nums[tail] = value;
            tail = (tail + 1) % n;
        }
    }

    // 出队
    public int poll() {
        if (head != tail) {
            int ans = nums[head];
            head = (head + 1) % n;
            return ans;
        }
        return -1;
    }

    public boolean isEmpty() {
        return head == tail;
    }
}
