class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        count = {}

        for x in arr:
            remainder = ((x % k) + k) % k
            count[remainder] = count.get(remainder, 0) + 1

        for key, freq in count.items():
            if key == 0:
                if freq % 2 != 0:
                    return False
            else:
                complement_freq = count.get(k - key, 0)
                if freq != complement_freq:
                    return False

        return True
        