/*
    KMP Algorithm to find the weather string of needle and Haystack is present
    create a prefix of needle which will tell that how much back you need to go when there is no match on the needle and haystack at perticular index.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.size();
        int n = haystack.size();

        vector<int> prefix(m);
        int i = 1,prev = 0;
        while(i<m){
            if(needle[i] == needle[prev]){
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
        
        int haystackPointer = 0, needlePointer = 0;
        while(haystackPointer<n){
            if(haystack[haystackPointer] == needle[needlePointer]){
                needlePointer++;
                haystackPointer++;
            } else {
                if(needlePointer == 0){
                    haystackPointer++;
                } else {
                    needlePointer = prefix[needlePointer-1];
                }
            }

            if(needlePointer == m){
                return haystackPointer - m;
            }
        }

        return -1;
    }
};