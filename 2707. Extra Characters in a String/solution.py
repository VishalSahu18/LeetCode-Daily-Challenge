class Solution:
    def recursion(self, s: str, idx: int, mp: dict, dp: list) -> int:
        if idx == len(s):
            return 0
        
        if dp[idx] != -1:
            return dp[idx]
        
        curr = ""
        curr_extra = 0
        min_extra = len(s)

        for i in range(idx, len(s)):
            curr += s[i]
            curr_extra = 0 if curr in mp else len(curr)
            nxt_extra = self.recursion(s, i + 1, mp, dp)
            total_extra = curr_extra + nxt_extra
            min_extra = min(min_extra, total_extra)

        dp[idx] = min_extra
        return dp[idx]

    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
         dp = [-1] * len(s)
         mp = {word: 1 for word in dictionary}
         return self.recursion(s, 0, mp, dp)
        