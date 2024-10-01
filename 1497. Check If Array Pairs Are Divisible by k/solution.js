/**
 * @param {number[]} arr
 * @param {number} k
 * @return {boolean}
 */
var canArrange = function(arr, k) {

    const count = new Map();

    for (let x of arr) {
        let remainder = ((x % k) + k) % k;
        count.set(remainder, (count.get(remainder) || 0) + 1);
    }

    for (let [key, freq] of count.entries()) {
        if (key === 0) {
            if (freq % 2 !== 0) {
                return false;
            }
        }else {
            let complementFreq = count.get(k - key) || 0;
            if (freq !== complementFreq) {
                return false;
            }
        }
    }

    return true;
    
};