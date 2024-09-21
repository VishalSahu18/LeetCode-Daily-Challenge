class Solution {
    public void dfs(int curr, int n, List<Integer> ans) {
        if (curr > n)
            return;

        ans.add(curr);

        for (int i = 0; i <= 9; i++) {
            if (curr * 10 + i > n)
                return;

            dfs(curr * 10 + i, n, ans);
        }
    }

    public List<Integer> lexicalOrder(int n) {
        List<Integer> ans = new ArrayList<>();
        for (int i = 1; i < 10; i++)
            dfs(i, n, ans);

        return ans;
    }
}