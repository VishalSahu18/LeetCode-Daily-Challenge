class Node:
    def __init__(self, val: int):
        self.val = val
        self.next = None
        self.prev = None

class MyCircularDeque:

    def __init__(self, k: int):
        self.totalSize = k
        self.currSize = 0
        self.front = None
        self.back = None

    def insertFront(self, value: int) -> bool:
        if self.currSize == self.totalSize:
            return False

        new_node = Node(value)

        if self.currSize == 0:
            self.front = self.back = new_node
        else:
            new_node.next = self.front
            self.front.prev = new_node
            self.front = new_node

        self.currSize += 1
        return True

    def insertLast(self, value: int) -> bool:
        if self.currSize == self.totalSize:
            return False

        new_node = Node(value)

        if self.currSize == 0:
            self.front = self.back = new_node
        else:
            self.back.next = new_node
            new_node.prev = self.back
            self.back = new_node

        self.currSize += 1
        return True

    def deleteFront(self) -> bool:
        if self.currSize == 0:
            return False

        tmp = self.front
        if self.front == self.back:
            self.front = self.back = None
        else:
            self.front = self.front.next
            self.front.prev = None

        self.currSize -= 1
        return True

    def deleteLast(self) -> bool:
        if self.currSize == 0:
            return False

        tmp = self.back
        if self.front == self.back:
            self.front = self.back = None
        else:
            self.back = self.back.prev
            self.back.next = None

        self.currSize -= 1
        return True

    def getFront(self) -> int:
        if self.currSize == 0:
            return -1
        return self.front.val

    def getRear(self) -> int:
        if self.currSize == 0:
            return -1
        return self.back.val

    def isEmpty(self) -> bool:
        return self.currSize == 0

    def isFull(self) -> bool:
        return self.currSize == self.totalSize
