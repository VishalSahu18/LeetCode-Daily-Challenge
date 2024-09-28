## Problem Link

https://leetcode.com/problems/design-circular-deque/description/?envType=daily-question&envId=2024-09-28

## Description

Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.<br>
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.<br>
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.<br>
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.<br>
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.<br>
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.<br>
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.<br>
boolean isEmpty() Returns true if the deque is empty, or false otherwise.<br>
boolean isFull() Returns true if the deque is full, or false otherwise.<br>

#### Example 1:

Input:

["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]

[[3], [1], [2], [3], [4], [], [], [], [4], []]

Output:

[null, true, true, true, false, 2, true, true, true, 4]


#### Explanation:

MyCircularDeque myCircularDeque = new MyCircularDeque(3);<br>
myCircularDeque.insertLast(1);  // return True<br>
myCircularDeque.insertLast(2);  // return True<br>
myCircularDeque.insertFront(3); // return True<br>
myCircularDeque.insertFront(4); // return False, the queue is full.<br>
myCircularDeque.getRear();      // return 2<br>
myCircularDeque.isFull();       // return True<br>
myCircularDeque.deleteLast();   // return True<br>
myCircularDeque.insertFront(4); // return True<br>
myCircularDeque.getFront();     // return 4<br>