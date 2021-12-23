import java.util.Scanner;

public class List {
    static class Node {
        int data;
        Node next;

        public Node(int d) {
            data = d;
        }
    }

    private Node head;

    // 有参构造函数
    public List(int d) {
        head = new Node(d);
    }

    // 打印链表
    public void print() {
        for (Node p = head; p != null; p = p.next) {
            System.out.print(p.data + ",");
        }
        System.out.println();
    }

    // 尾部添加元素，时间复杂度O(1)
    public void append(int d) {
        Node r = new Node(d);
        if (head == null) {
            head = r;
        } else {
            Node p = head;
            while (p.next != null)
                p = p.next; // 寻找插入位置
            p.next = r;
        }
    }

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        List l = new List(10);
        Scanner scanner = new Scanner(System.in);
        for (int x; (x = scanner.nextInt()) != -1; ) {
            l.append(x);
            l.print();
        }
        in.close();
    }
}