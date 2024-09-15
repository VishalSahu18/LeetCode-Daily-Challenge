class Solution:
    def is_vowel(self, c):
        return c in 'aeiou'

    def findTheLongestSubstring(self, s: str) -> int:
        n = len(s)
        mask = 0
        res = 0
        index = [-1] * 32
        index[0] = -1
        position = {'a': 0, 'e': 1, 'i': 2, 'o': 3, 'u': 4}

        for i in range(n):
            if self.is_vowel(s[i]):
                mask ^= (1 << position[s[i]])

            if mask != 0 and index[mask] == -1:
                index[mask] = i

            res = max(res, i - index[mask])

        return res