/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number}
 */
var longestCommonPrefix = function(arr1, arr2) {

    let st = new Set();
    let n1 = arr1.length, n2 = arr2.length, mx = 0;

    for (let i = 0; i < n1; i++) {
        let curr = "";
        let str = arr1[i].toString();
        for (let x of str) {
            curr += x;
            st.add(curr);
        }
    }

    for (let i = 0; i < n2; i++) {
        let curr = "";
        let str = arr2[i].toString();
        for (let x of str) {
            curr += x;
            if (st.has(curr)) {
                mx = Math.max(mx, curr.length);
            }
        }
    }

    return mx;   
};