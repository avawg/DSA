import java.util.HashMap;
import java.util.Map;

// 模拟实现最小堆，用于dijkstra 和 prim 算法
public class MinHeap {

    private Node[] nodes;
    private int size;
    private Map<Integer, Integer> entry = new HashMap<>(); // 记录节点在堆中位置

    public MinHeap(int n) {
        nodes = new Node[n + 1];
        size = 0;
    }

    // 交换min-heap中值，并更新key映射
    private void swap(int i, int j) {
        Node t = nodes[i];
        nodes[i] = nodes[j];
        nodes[j] = t;
        entry.put(nodes[i].id, i);
        entry.put(nodes[j].id, j);
    }

    // 插入元素 时间复杂度O(logn)
    public void add(int id, int val) {
        Node node = new Node(id, val);
        nodes[++size] = node;
        entry.put(id, size);
        int i = size;
        while (i > 1) {
            if (nodes[i].dist < nodes[i / 2].dist) {
                swap(i, i / 2);
                i /= 2;
            } else {
                break;
            }
        }
    }

    // 删除最小元素 时间复杂度O(logn)
    public Node remove() {
        Node node = nodes[1];
        entry.remove(node.id);
        // 将数组尾元素移到首部
        nodes[1] = nodes[size--];
        entry.put(nodes[1].id, 1);
        // 更新堆
        int i = 1;
        while (2 * i <= size) {
            int j = 2 * i;
            if (j + 1 <= size && nodes[j + 1].dist < nodes[j].dist) { // 选取nodes[s]节点的两个子节点，较小者
                j += 1;
            }
            if (nodes[i].dist <= nodes[j].dist) { // 将nodes[i]与nodes[j]比较
                break;
            } else {
                swap(i, j);
                i = j;
            }
        }
        return node;
    }

    // 降低堆中某个元素的值 时间复杂度O(logn)
    public void decrease(int id, int val) {
        int i = entry.get(id);
        nodes[i].dist = val;

        while (i > 1) {
            if (nodes[i].dist < nodes[i / 2].dist) {
                swap(i, i / 2);
                i /= 2;
            } else {
                break;
            }
        }
    }

    public boolean isEmpty() {
        return size == 0;
    }
}
