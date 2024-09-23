class Solution {
private:

    int recursion(string &s,int idx,unordered_map<string,int>&mp,int *dp){

        if(idx == s.size())
            return 0;

        if(dp[idx]!=-1)
            return dp[idx];

        string curr = "";
        int currExtra = 0;  
        int minExtra = s.size();

        for(int i=idx;i<s.size();i++){

            curr += s[i];
            currExtra = mp.count(curr) ? 0 : curr.size();
            int nxtExtra = recursion(s,i+1,mp,dp);
            int totalExtra = currExtra + nxtExtra;
            minExtra = min(minExtra,totalExtra);
        }

        return dp[idx] = minExtra;
    }
    
public:
    int minExtraChar(string s, vector<string>& dictionary) {

        int dp[s.size()];
        memset(dp,-1,sizeof(dp));
        unordered_map<string,int>mp;

        for(auto &x : dictionary)
             mp[x]++;

        return recursion(s,0,mp,dp);
    }
};