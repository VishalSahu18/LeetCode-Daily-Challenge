class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>nums(arr);
        unordered_map<int,int>index;
        sort(begin(nums),end(nums));
        int rank = 1 , n = arr.size();

        for(int i=0;i<n;i++){
            int val = nums[i];
            if(!index.count(val)){
                index[val] = rank;
                rank++;
            }   
        }

        for(int i=0;i<n;i++)
            nums[i] = index[arr[i]];
        
        return nums;
    }
};