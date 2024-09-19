class Solution {
public:
    unordered_map<string,vector<int>>map;
    
    vector<int> recursion(string curr){

        if(map.find(curr)!=map.end())
            return map[curr];
        
        vector<int>ans;
        int n = curr.size();
        
       for(int i = 0 ;i<n;i++){
        
            char c = curr[i];

              if(c=='-' || c=='*' || c=='+'){
                  vector<int>a = recursion(curr.substr(0,i));
                  vector<int>b = recursion(curr.substr(i+1));
                  
                  for(auto x : a){
                      for(auto y : b){

                          int z = 0;
                          
                          if(c=='-'){
                              z = x - y;
                          }else if(c=='+'){
                              z = x + y;
                          }else{
                              z = x * y;
                          }
                          
                          ans.push_back(z);
                          
                      }
                  }
                  
              }
         }
        
        if(ans.size()==0)
            ans.push_back(stoi(curr));
        
        map[curr] = ans;
        
        return ans;
     }
    
    vector<int> diffWaysToCompute(string expression) { 
         return recursion(expression);
    }
};