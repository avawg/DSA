class CircularQueue {

    int[] nums;
    int head, tail, size; // 用size区分为空还是为满
    // h&t     h t     h     t      ...t h ...   .... h&t ...
    // null    1       1 2 3        ...  1 ...   ...k  1  ...
    int capacity;

    public CircularQueue(int k) {
        nums = new int[k];
        head = tail = size = 0;
        capacity = k;
    }

    // 入队
    public void offer(int value) {
        if (size < capacity) {
            nums[tail] = value;
            tail = (tail + 1) % capacity;
            ++size;
        }
    }

    // 出队
    public int poll() {
        if (size > 0) {
            int ans = nums[head];
            head = (head + 1) % capacity;
            --size;
            return ans;
        }
        return -1;
    }

    public boolean isEmpty() {
        return size == 0;
    }
}
