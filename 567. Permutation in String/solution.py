class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n1, n2, l, r = len(s1), len(s2), 0, 0
        count = [0] * 26

        for c in s1:
            count[ord(c) - ord('a')] += 1

        while r < n2:
            count[ord(s2[r]) - ord('a')] -= 1
            n1 -= 1

            while count[ord(s2[r]) - ord('a')] < 0:
                count[ord(s2[l]) - ord('a')] += 1
                l += 1
                n1 += 1

            if n1 == 0:
                return True
            r += 1

        return False
        