/*
    its just the needle to calculate and the last index of the prefix array will tell me the actual result.

*/


class Solution {
public:
    string longestPrefix(string s) {
        vector<int> prefix(s.size(),0);
        int i=1,prev = 0;
        while(i<s.size()){
            if(s[i] == s[prev]){
                prefix[i] = prev+1;
                prev++;
                i++;
            } else {
                if(prev == 0){
                    prefix[i] = 0;
                    i++;
                } else {
                    prev = prefix[prev-1];
                }
            }
        }

        return s.substr(0,prefix[s.size()-1]);
    }
};