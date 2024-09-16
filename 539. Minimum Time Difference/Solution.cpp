class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {

       int min_diff = 24*60+1;
       vector<bool>visit(24*60+1);

       for(auto &x : timePoints){

           int hh = stoi(x.substr(0,2));
           int mm = stoi(x.substr(3,2));

           if(visit[hh*60+mm])
               return 0;

           visit[hh*60 + mm] = true;
       }

        int first = 24*60+1;
        int prevMinute = -1;

        for(int i=0;i<=24*60;i++){
                
                if(visit[i]){

                    if(prevMinute!=-1)
                        min_diff = min(min_diff,i-prevMinute);

                    prevMinute = i;
                    first = min(first,i);
                }
        }
        
        return min(min_diff, (24*60 - prevMinute) + first);

    }
};