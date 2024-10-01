/**
 * @param {number[]} arr
 * @return {number[]}
 */
var arrayRankTransform = function(arr) {

    const n = arr.length;
    const mp = new Map();
    const nums = [...arr];

    nums.sort((a, b) => a - b); 
    let rank = 1;

    for (let num of nums) {
        if (!mp.has(num)) {
            mp.set(num, rank);
            rank++;
        }
    }

    return arr.map(num => mp.get(num));
};