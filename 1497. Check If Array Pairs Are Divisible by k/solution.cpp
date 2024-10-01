class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {

        unordered_map<int,int>count;

        for(auto &x : arr){
            int remainder = ((x%k)+k)%k; // for handling negative numbers
            count[remainder]++;
        }
            

        for(auto &x : count){
           if(x.first==0){
                if(x.second&1)
                    return false;
           }else if(x.second!=count[k-x.first]){
               return false;
           }
        }
        return true;

    }
};