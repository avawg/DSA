import java.util.Scanner;

public class LinkedList {
    static class ListNode {
        int val;
        ListNode next;

        public ListNode(int val) {
            this.val = val;
        }
    }

    private ListNode head;

    // 打印链表
    public void print() {
        for (ListNode p = head; p != null; p = p.next) {
            System.out.print(p.val + ",");
        }
        System.out.println();
    }

    // 尾部添加元素，时间复杂度O(n)
    public void add(int val) {
        ListNode r = new ListNode(val);
        if (head == null) {
            head = r;
        } else {
            ListNode p = head;
            while (p.next != null)
                p = p.next; // 寻找插入位置
            p.next = r;
        }
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        Scanner scanner = new Scanner(System.in);
        for (int x; (x = scanner.nextInt()) != -1; ) {
            list.add(x);
            list.print();
        }
        scanner.close();
    }
}
