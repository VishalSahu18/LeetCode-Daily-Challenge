class Solution:
    def dfs(self, curr: int, n: int, ans: List[int]):
        if curr > n:
            return

        ans.append(curr)

        for i in range(10):
            if curr * 10 + i > n:
                return
            self.dfs(curr * 10 + i, n, ans)

    def lexicalOrder(self, n: int) -> List[int]:
        ans = []
        for i in range(1, 10):
            self.dfs(i, n, ans)
        return ans
