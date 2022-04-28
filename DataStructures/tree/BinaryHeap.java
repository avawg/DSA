import java.util.HashMap;
import java.util.Map;

/**
 *  模拟实现二叉堆 小顶堆
 */
public class BinaryHeap {

    private int[] nums;
    private int size;

    public BinaryHeap(int n) {
        nums = new int[n];
        size = 0;
    }

    /**
     * 插入元素，时间复杂度O(logn)
     */
    public void offer(int val) {
        nums[size] = val;
        for (int i = size; i > 0; ) {
            if (nums[i] < nums[(i - 1) / 2]) {
                swap(i, (i - 1) / 2);
                i = (i - 1) / 2;
            } else {
                break;
            }
        }
        size++;
    }

    /**
     * 删除最小元素，时间复杂度O(logn)
     */
    public int poll() {
        int ans = nums[0];
        nums[0] = nums[--size];
        // 更新堆
        for (int i = 0; 2 * i + 1 < size; ) {
            int j = 2 * i + 1;
            if (j + 1 < size && nums[j + 1] < nums[j]) { // 选取nums[i]节点的两个子节点，较小者
                ++j;
            }
            if (nums[i] <= nums[j]) { // 将nums[i]与nums[j]比较
                break;
            } else {
                swap(i, j);
                i = j;
            }
        }
        return ans;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    private void swap(int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

    public static void main(String[] args) {
        BinaryHeap heap = new BinaryHeap(10);
        for (int i = 0; i < 10; i++) {
            heap.offer(2 * i + 1);
        }
        System.out.println(heap.poll());
        System.out.println(heap.poll());
    }
}
