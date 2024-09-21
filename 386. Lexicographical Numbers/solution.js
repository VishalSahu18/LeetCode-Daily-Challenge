/**
 * @param {number} n
 * @return {number[]}
 */

function dfs(curr, n, ans) {
    if (curr > n) return;

    ans.push(curr);

    for (let i = 0; i <= 9; i++) {
        if (curr * 10 + i > n) return;

        dfs(curr * 10 + i, n, ans);
    }
}

var lexicalOrder = function(n) {
    var ans = [];
    for (let i = 1; i < 10; i++) {
        dfs(i, n, ans);
    }

    return ans;
};