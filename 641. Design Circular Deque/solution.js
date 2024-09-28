class Node {
    constructor(val) {
        this.val = val;
        this.next = null;
        this.prev = null;
    }
}

/**
 * @param {number} k
 */
var MyCircularDeque = function(k) {
    this.totalSize = k;
    this.currSize = 0;
    this.front = null;
    this.back = null;
};

/** 
 * @param {number} value
 * @return {boolean}
 */
MyCircularDeque.prototype.insertFront = function(value) {
    if (this.currSize === this.totalSize) {
        return false;
    }

    const newNode = new Node(value);

    if (this.currSize === 0) {
        this.front = this.back = newNode;
    } else {
        newNode.next = this.front;
        this.front.prev = newNode;
        this.front = newNode;
    }

    this.currSize++;
    return true;
};

/** 
 * @param {number} value
 * @return {boolean}
 */
MyCircularDeque.prototype.insertLast = function(value) {
    if (this.currSize === this.totalSize) {
        return false;
    }

    const newNode = new Node(value);

    if (this.currSize === 0) {
        this.front = this.back = newNode;
    } else {
        this.back.next = newNode;
        newNode.prev = this.back;
        this.back = newNode;
    }

    this.currSize++;
    return true;
};

/**
 * @return {boolean}
 */
MyCircularDeque.prototype.deleteFront = function() {
    if (this.currSize === 0) {
        return false;
    }

    const tmp = this.front;
    if (this.front === this.back) {
        this.front = this.back = null;
    } else {
        this.front = this.front.next;
        this.front.prev = null;
    }

    this.currSize--;
    return true;
};

/**
 * @return {boolean}
 */
MyCircularDeque.prototype.deleteLast = function() {
    if (this.currSize === 0) {
        return false;
    }

    const tmp = this.back;
    if (this.front === this.back) {
        this.front = this.back = null;
    } else {
        this.back = this.back.prev;
        this.back.next = null;
    }

    this.currSize--;
    return true;
};

/**
 * @return {number}
 */
MyCircularDeque.prototype.getFront = function() {
    return this.currSize === 0 ? -1 : this.front.val;
};

/**
 * @return {number}
 */
MyCircularDeque.prototype.getRear = function() {
    return this.currSize === 0 ? -1 : this.back.val;
};

/**
 * @return {boolean}
 */
MyCircularDeque.prototype.isEmpty = function() {
    return this.currSize === 0;
};

/**
 * @return {boolean}
 */
MyCircularDeque.prototype.isFull = function() {
    return this.currSize === this.totalSize;
};