class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<string>st;
        int n1 = arr1.size(), n2 = arr2.size(),mx=0;

        for(int i=0;i<n1;i++){
            string curr = "";
            string str = to_string(arr1[i]);
            for(auto &x : str){
                curr+=x;
                st.insert(curr);
            }      
        }

        for(int i=0;i<n2;i++){
            string str = to_string(arr2[i]);
            string curr = "";

            for(auto &x : str){
                curr+= x;
                if(st.count(curr)){
                    mx = max(mx,(int)curr.length());
                }
            }
        }
        
        return mx;
        
    }
};