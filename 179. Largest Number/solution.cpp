class Solution {     
public:
    static bool comp(string a,string b){
        return a+b>b+a;
    }
       
     string largestNumber(vector<int>& nums) {
        
        int n  = nums.size();
        vector<string> store(n);
        
        for(int i=0;i<n;i++)
            store[i] = to_string(nums[i]);
        
        
        sort(store.begin(),store.end(),comp);
        string ans ="";
        
        for(auto x:store)
           ans+=x;
        
        return ans[0] =='0'?"0":ans;
          
    }
};