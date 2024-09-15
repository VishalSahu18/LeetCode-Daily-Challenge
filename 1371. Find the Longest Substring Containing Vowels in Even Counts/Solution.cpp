class Solution {
private:
    bool isVowel(char c){
        return (c=='a' || c=='e'|| c=='i'||c=='o'||c=='u');
    }

public:
    int findTheLongestSubstring(string s) {

        int n = s.size(), mask = 0,res = 0;
        vector<int>index(32,-1);
        unordered_map<char,int>position = {{'a',0},{'e',1},{'i',2},{'o',3},{'u',4}};
        
        for(int  i= 0;i<n;i++){

             if(isVowel(s[i]))
                  mask  ^=  1<<(position[s[i]]);
             
              if(mask!= 0 && index[mask]==-1)
                   index[mask] = i;
             
              res = max(res , i -  index[mask]);     
       }
        
        return res;
    }
};