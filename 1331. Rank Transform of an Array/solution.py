class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        n = len(arr)
        map = {}
        nums = arr[:]

        nums.sort()
        rank = 1

        for num in nums:
            if num not in map:
                map[num] = rank
                rank += 1

        return [map[num] for num in arr]