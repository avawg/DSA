import java.util.HashMap;
import java.util.Map;

// 支持decrease-key的最小堆, 这里堆中元素是数字 也是map中key, 插入更新后的值不能重复
// 在图应用中, key可以是节点id 没有限制
public class BinaryHeap {

    private int[] nums;
    private int size;
    private Map<Integer, Integer> entry = new HashMap<>(); // 记录节点在堆中位置

    public BinaryHeap(int n) {
        nums = new int[n];
        size = 0;
    }

    // 插入元素，时间复杂度O(logn)
    public void add(int val) {
        nums[size] = val;
        entry.put(val, size++);
        for (int i = size - 1; i > 0; ) {
            if (nums[i] < nums[(i - 1) / 2]) {
                swap(i, (i - 1) / 2);
                i = (i - 1) / 2;
            } else {
                break;
            }
        }
    }

    // 删除最小元素，时间复杂度O(logn)
    public int remove() {
        int res = nums[0];
        entry.remove(nums[0]);
        // 将数组尾元素移到首部
        entry.put(nums[0] = nums[--size], 0);
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
        return res;
    }

    // 降低堆中某个元素的值，时间复杂度O(logn)
    public void decrease(int val, int newVal) {
        int i = entry.get(val);
        nums[i] = newVal;
        while (i > 0) {
            if (nums[i] < nums[(i - 1) / 2]) {
                swap(i, (i - 1) / 2);
                i = (i - 1) / 2;
            } else {
                break;
            }
        }
    }

    public boolean isEmpty() {
        return size == 0;
    }

    // 交换min-heap中值，并更新key映射
    private void swap(int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        entry.put(nums[i], i);
        entry.put(nums[j], j);
    }

    public static void main(String[] args) {
        BinaryHeap heap = new BinaryHeap(10);
        for (int i = 0; i < 10; i++) {
            heap.add(2 * i + 1);
        }
        System.out.println(heap.remove());
        heap.decrease(11, -10);
        System.out.println(heap.remove());
    }
}