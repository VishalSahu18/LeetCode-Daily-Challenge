/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void dfs(int curr, int n, int* ans, int* idx) {
    if (curr > n)
        return;

    ans[(*idx)++] = curr;

    for (int i = 0; i <= 9; i++) {
        if (curr * 10 + i > n)
            return;

        dfs(curr * 10 + i, n, ans, idx);
    }
}

int* lexicalOrder(int n, int* returnSize) {
    int* ans = (int*)malloc(n * sizeof(int));
    int idx = 0;
    for (int i = 1; i < 10; i++)
        dfs(i, n, ans, &idx);

    *returnSize = idx;
    return ans;
}