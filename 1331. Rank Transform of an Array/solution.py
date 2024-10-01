class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        n = len(arr)
        hm = {}
        nums = arr[:]

        nums.sort()
        rank = 1

        for num in nums:
            if num not in hm:
                hm[num] = rank
                rank += 1

        return [hm[num] for num in arr]