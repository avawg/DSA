import java.util.LinkedList;

public class Deque {
    static class Node {
        int data;
        Node prev, next;
        public Node(Node prev, int d, Node next) {
            data = d;
            this.prev = prev;
            this.next = next;
        }
	}

	private int size;
	private Node first, last;

	public Deque() {
		size = 0;
		first = last = null;
	}

	// 队尾入队，时间复杂度O(1)
	public void push(int x) {
		Node l = last;
		Node node = new Node(l, x, null);
		last = node;
		if (first == null)  // 队伍为空
			first = node;
		else
			l.next = node;
	    size++;
	}

	// 出队，并返回出队值，时间复杂度O(1)
	public int pop(int c) {
		Node node;
	    if (size == 1) { // 只有一个元素，出队后队伍为空
	        node = first;
			first = last = null;
	    } else {
	        if (c == 0) { // c=0队头出队
	            node = first;
	            first = first.next;
				first.prev = null;
	        } else { // c=1队尾出队
	            node = last;
				last = last.prev;
				last.next = null;
	        }
	    }
	    size--;
	    node.prev = node.next = null;
	    return node.data; // 返回出队值
	}

	public int lastVal() {
		return last.data;
	}

	public int firstVal() {
		return first.data;
	}

	public boolean empty() {
		return size == 0;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Deque que = new Deque();
	    que.push(19);
	    que.push(88);
	    que.push(300);
	    System.out.println(que.firstVal());
	    System.out.println(que.lastVal());
	    System.out.println(que.pop(0));
	    System.out.println(que.pop(1));
	    System.out.println(que.empty());
	}
}