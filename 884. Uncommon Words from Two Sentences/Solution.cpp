class Solution {
public:
    void storeString(unordered_map<string,int>&count,string &s){

        int n = s.length();
        string curr = "";

        for(int i=0;i<n;i++){
            if(s[i]==' '){
                count[curr]++;
                curr = "";
            }else{
                curr+= s[i];
            }
        }
        count[curr]++;
    }

    vector<string> uncommonFromSentences(string s1, string s2) {

        unordered_map<string ,int>count;
        vector<string>ans;

        storeString(count,s1);
        storeString(count,s2);
       
        for(auto &x : count)
            if(x.second==1)
                ans.push_back(x.first);

        return ans;
        
    }
};