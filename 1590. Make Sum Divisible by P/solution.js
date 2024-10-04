/**
 * @param {number[]} nums
 * @param {number} p
 * @return {number}
 */
var minSubarray = function(nums, p) {
    let targetSum = nums.reduce((acc, num) => acc + num, 0) % p;
    const n = nums.length;
    let minLen = n, currSum = 0;

    if (targetSum === 0) {
        return 0;
    }

    const remainderIdx = new Map();
    remainderIdx.set(0, -1);

    for (let i = 0; i < n; i++) {
        currSum = (currSum + nums[i]) % p;
        let diff = (currSum - targetSum + p) % p;

        if (remainderIdx.has(diff)) {
            minLen = Math.min(minLen, i - remainderIdx.get(diff));
        }

        remainderIdx.set(currSum, i);
    }

    return minLen === n ? -1 : minLen;
};