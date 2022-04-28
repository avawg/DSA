public class Deque {
    static class Node {
        int val;
        Node prev, next;
        public Node(int val, Node prev, Node next) {
            this.val = val;
            this.prev = prev;
            this.next = next;
        }
	}

	private int size;
	private Node head, tail;

	public Deque() {
		size = 0;
		head = tail = null;
	}

	// 队尾入队，时间复杂度O(1)
	public void offer(int val) {
		Node node = new Node(val, tail, null);
		if (head == null) { // 队伍为空
			head = tail = node;
		} else {
			tail.next = node;
			tail = node;
		}
	    size++;
	}

	// 出队，并返回出队值，时间复杂度O(1)
	public int poll(int type) {
		Node node = null;
	    if (size == 1) { // 只有一个元素，出队后队伍为空
	        node = head;
			head = tail = null;
	    } else {
	        if (type == 0) { // type=0队头出队
	            node = head;
	            head = head.next;
				head.prev = null;
	        } else { // type=1队尾出队
	            node = tail;
				tail = tail.prev;
				tail.next = null;
	        }
	    }
	    size--;
	    node.prev = node.next = null;
	    return node.val; // 返回出队值
	}

	public int peekLast() {
		return tail.val;
	}

	public int peekFirst() {
		return head.val;
	}

	public boolean isEmpty() {
		return size == 0;
	}

	public static void main(String[] args) {
		Deque que = new Deque();
	    que.offer(19);
	    que.offer(88);
	    que.offer(300);
	    System.out.println(que.peekFirst());
	    System.out.println(que.peekLast());
	    System.out.println(que.poll(0));
	    System.out.println(que.poll(1));
	    System.out.println(que.isEmpty());
	}
}
