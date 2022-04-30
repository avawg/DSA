
/**
 * 你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。
 * 锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。
 * 列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。
 * 字符串 target 代表可以解锁的数字，你需要给出解锁需要的最小旋转次数，如果无论如何不能解锁，返回 -1
 */

 class Solution {

    Set<String> set;

    public int openLock(String[] deadends, String t) {
        set = new HashSet<>(Arrays.asList(deadends));
        String s = "0000";
        if (set.contains(s)) {
            return -1;
        }
        if (s.equals(t)) {
            return 0;
        }
        // bidirectional bfs
        Queue<String> q1 = new LinkedList<>(), q2 = new LinkedList<>();
        Map<String, Integer> m1 = new HashMap<>(), m2 = new HashMap<>();
        m1.put(s, 0);
        q1.offer(s);
        m2.put(t, 0);
        q2.offer(t);
        // 如果一个队列为空，说明从该方向找不到其目标节点了
        while (!q1.isEmpty() && !q2.isEmpty()) {
            int ret = -1;
            if (q1.size() <= q2.size()) { // 让两个搜索方向平均
                ret = update(q1, m1, m2);
            } else {
                ret = update(q2, m2, m1);
            }
            if (ret != -1) return ret;
        }
        return -1;
    }

    int update(Queue<String> q, Map<String, Integer> m1, Map<String, Integer> m2) {
        String s = q.poll();
        char[] arr = s.toCharArray();
        for (int i = 0; i < 4; i++) {
            int k = arr[i] - '0';
            for (int j = -1; j <= 1; j++) {
                if (j == 0) continue;
                arr[i] = (char)('0' + (k + j + 10) % 10);
                String next = new String(arr);
                // 在另一方向找到过，说明找到最短路
                if (m2.containsKey(next)) {
                    return m1.get(s) + 1 + m2.get(next);
                }
                if (!m1.containsKey(next) && !set.contains(next)) {
                    m1.put(next, m1.get(s) + 1);
                    q.offer(next);
                }
            }
            arr[i] = (char) ('0' + k);
        }
        return -1;
    }
}
