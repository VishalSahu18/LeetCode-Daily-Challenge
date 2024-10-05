/**
 * @param {string} s1
 * @param {string} s2
 * @return {boolean}
 */
var checkInclusion = function(s1, s2) {
    let n1 = s1.length, n2 = s2.length, l = 0, r = 0;
    let count = Array(26).fill(0);

    for (let char of s1) {
        count[char.charCodeAt() - 'a'.charCodeAt()]++;
    }

    while (r < n2) {
        count[s2.charCodeAt(r) - 'a'.charCodeAt()]--;
        n1--;

        while (count[s2.charCodeAt(r) - 'a'.charCodeAt()] < 0) {
            count[s2.charCodeAt(l++) - 'a'.charCodeAt()]++;
            n1++;
        }

        if (n1 == 0)
            return true;
        r++;
    }
    return false; 
};