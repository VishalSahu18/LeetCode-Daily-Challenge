/**
 * @param {string} s
 * @param {string[]} dictionary
 * @return {number}
 */
var minExtraChar = function(s, dictionary) {

    const recursion = (s, idx, mp, dp) => {
        if (idx === s.length) {
            return 0;
        }

        if (dp[idx] !== -1) {
            return dp[idx];
        }

        let curr = "";
        let currExtra = 0;
        let minExtra = s.length;

        for (let i = idx; i < s.length; i++) {
            curr += s[i];
            currExtra = mp.has(curr) ? 0 : curr.length;
            let nxtExtra = recursion(s, i + 1, mp, dp);
            let totalExtra = currExtra + nxtExtra;
            minExtra = Math.min(minExtra, totalExtra);
        }

        return dp[idx] = minExtra;
    };

    let dp = new Array(s.length).fill(-1);
    let mp = new Map();

    dictionary.forEach((word) => {
        mp.set(word, (mp.get(word) || 0) + 1);
    });

    return recursion(s, 0, mp, dp);
};
