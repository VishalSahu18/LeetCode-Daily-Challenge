class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        int targetSum  = accumulate(begin(nums),end(nums),0L)%p,n = nums.size() , minLen = n , currSum = 0;

        if(targetSum == 0)
            return 0;

        unordered_map<int,int>remainder_idx;
        remainder_idx[0] = -1;

        for(int i=0;i<n;i++){
            currSum = (currSum + nums[i])%p;
            int diff = (currSum - targetSum + p)%p;

            if(remainder_idx.count(diff)>0)
                minLen = min(minLen,i-remainder_idx[diff]);

            remainder_idx[currSum] = i;
        }
        return minLen == n ? -1 : minLen;   
    }
};