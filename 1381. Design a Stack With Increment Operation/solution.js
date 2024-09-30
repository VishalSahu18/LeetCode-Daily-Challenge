/**
 * @param {number} maxSize
 */
var CustomStack = function(maxSize) {
    this.nums = [];
    this.mxSize = maxSize;
};

/** 
 * @param {number} x
 * @return {void}
 */
CustomStack.prototype.push = function(x) {
     if (this.nums.length === this.mxSize) return;
        this.nums.push(x);
};

/**
 * @return {number}
 */
CustomStack.prototype.pop = function() {
     if (this.nums.length === 0) return -1;
        return this.nums.pop();
};

/** 
 * @param {number} k 
 * @param {number} val
 * @return {void}
 */
CustomStack.prototype.increment = function(k, val) {
     for (let i = 0; i < k && i < this.nums.length; i++) {
            this.nums[i] += val;
      }  
};
