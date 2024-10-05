class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n1 = s1.size() , n2 = s2.size(),l = 0 , r = 0 , count[26] = {};

        for(auto &x : s1)
            count[x-'a']++;

        while(r<n2){
            count[s2[r]-'a']--;
            n1--;

            while(count[s2[r]-'a']<0){
                count[s2[l++]-'a']++;
                n1++;
            }

            if(n1==0)
                return true;
            r++;
        }
        return false;
    }
};