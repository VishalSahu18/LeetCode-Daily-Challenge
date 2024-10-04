class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        target_sum = sum(nums) % p
        n = len(nums)
        min_len = n
        curr_sum = 0
        
        if target_sum == 0:
            return 0

        remainder_idx = {0: -1}

        for i in range(n):
            curr_sum = (curr_sum + nums[i]) % p
            diff = (curr_sum - target_sum + p) % p

            if diff in remainder_idx:
                min_len = min(min_len, i - remainder_idx[diff])

            remainder_idx[curr_sum] = i

        return min_len if min_len != n else -1
        