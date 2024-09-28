class Node {
    int val;
    Node next, prev;

    // Constructor for Node
    public Node(int val) {
        this.val = val;
        this.next = null;
        this.prev = null;
    }
}

class MyCircularDeque {
    private int currSize, totalSize;
    private Node front, back;

    // Constructor to initialize the deque with size k
    public MyCircularDeque(int k) {
        totalSize = k;
        currSize = 0;
        front = null;
        back = null;
    }

    // Insert an element at the front of the deque
    public boolean insertFront(int value) {
        if (currSize == totalSize) {
            return false; // Deque is full
        }

        Node newNode = new Node(value);

        if (currSize == 0) { // If the deque is empty
            front = back = newNode;
        } else {
            newNode.next = front;
            front.prev = newNode;
            front = newNode;
        }

        currSize++;
        return true;
    }

    // Insert an element at the end of the deque
    public boolean insertLast(int value) {
        if (currSize == totalSize) {
            return false; // Deque is full
        }

        Node newNode = new Node(value);

        if (currSize == 0) { // If the deque is empty
            front = back = newNode;
        } else {
            back.next = newNode;
            newNode.prev = back;
            back = newNode;
        }

        currSize++;
        return true;
    }

    // Delete the element from the front of the deque
    public boolean deleteFront() {
        if (currSize == 0) {
            return false; // Deque is empty
        }

        Node tmp = front;
        front = front.next;

        if (front != null) {
            front.prev = null;
        } else {
            back = null; // Deque is now empty
        }

        tmp.next = null; // Help with garbage collection
        currSize--;
        return true;
    }

    // Delete the element from the end of the deque
    public boolean deleteLast() {
        if (currSize == 0) {
            return false; // Deque is empty
        }

        Node tmp = back;
        back = back.prev;

        if (back != null) {
            back.next = null;
        } else {
            front = null; // Deque is now empty
        }

        tmp.prev = null; // Help with garbage collection
        currSize--;
        return true;
    }

    // Get the front element of the deque
    public int getFront() {
        if (currSize == 0) {
            return -1; // Deque is empty
        }
        return front.val;
    }

    // Get the last element of the deque
    public int getRear() {
        if (currSize == 0) {
            return -1; // Deque is empty
        }
        return back.val;
    }

    // Check if the deque is empty
    public boolean isEmpty() {
        return currSize == 0;
    }

    // Check if the deque is full
    public boolean isFull() {
        return currSize == totalSize;
    }
}
