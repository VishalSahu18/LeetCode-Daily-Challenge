class Solution {
    public int minSubarray(int[] nums, int p) {

        long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        long targetSum = totalSum % p;
        int n = nums.length, minLen = n;
        long currSum = 0;

        if (targetSum == 0) {
            return 0;
        }

        Map<Long, Integer> remainderIdx = new HashMap<>();
        remainderIdx.put(0L, -1);

        for (int i = 0; i < n; i++) {
            currSum = (currSum + nums[i]) % p;
            long diff = (currSum - targetSum + p) % p;

            if (remainderIdx.containsKey(diff)) {
                minLen = Math.min(minLen, i - remainderIdx.get(diff));
            }

            remainderIdx.put(currSum, i);
        }

        return minLen == n ? -1 : minLen;  
    }
}