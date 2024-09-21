class Solution {
public:
    void dfs(int curr,int n, vector<int>&ans){

        if(curr>n)
            return;
        
        ans.push_back(curr);
        
        for(int i=0;i<=9;i++){

            if(curr*10 + i > n)
                return;

            dfs(curr*10+i,n,ans);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int i=1;i<10;i++)
            dfs(i,n,ans);  

        return ans;
    }
};