class Solution:
    def shortestPalindrome(self, s: str) -> str:
        rev = s[::-1]
        tmp = s + "#" + rev

        n = len(tmp)

        # building lookup table (lps[] longest proper suffix) using KMP algorithm
        lps = [0] * n
        index = 0
        lps[0] = 0

        for i in range(1, n):
            if tmp[i] == tmp[index]:
                lps[i] = lps[i - 1] + 1
                index += 1
            else:
                index = lps[i - 1]

                while index > 0 and tmp[index] != tmp[i]:
                    index = lps[index - 1]

                if tmp[index] == tmp[i]:
                    index += 1

                lps[i] = index

        pos = lps[n - 1]
        res = s[pos:][::-1]

        return res + s
