class Solution {

public:
    string shortestPalindrome(string s) {
        
      string rev = s;
      reverse(begin(rev),end(rev));
      string tmp = s + "#" + rev;
        
      int n = tmp.size();
        
      // building lookup table (lps[]  longest proper suffix) using kmp algorithm
      
       int lps[n];
       int index = 0;
       lps[0] = 0;
        
        for(int i=1;i<n;i++){
            
            if(tmp[i] == tmp[index]){
                lps[i] = lps[i-1] + 1;
                index++;
            }else{
                
                index  = lps[i-1];
                
                while(index > 0 && tmp[index]!=tmp[i]){
                    index = lps[index-1];
                }
                
                if(tmp[index] == tmp[i])
                    index++;
                
                lps[i] = index;
            }
            
        }
        
         int pos = lps[n-1];
         string res = s.substr(pos);
         reverse(begin(res),end(res));
        
        return res + s;
         
    }
};