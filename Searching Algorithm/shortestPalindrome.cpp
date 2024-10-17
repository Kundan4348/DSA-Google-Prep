/*
    Simply calculate the prefix plindrome starting from 0 index.
    by reversing the string and then applying the KMP also as a needle
    add the substring from the end of the reversed string (s) to the original string and return
*/


class Solution {
public:
    
    //KMP string matching algorithm
    string shortestPalindrome(string s) {
        string str=s;
        reverse(s.begin(),s.end());
        string newStr=str+'#'+s;
        vector<int> kmp(newStr.size(),0);
        int j=0;
        for(int i=1;i<newStr.size();++i){
            while(j>0 && newStr[i]!=newStr[j]){
                j=kmp[j-1];
            }
            
            if(newStr[i]==newStr[j]){
                kmp[i]=j+1;
                j++;
            }
        }
        // for(int i=0;i<kmp.size();++i)
        //     cout<<kmp[i]<<" ";
        
        
        return s.substr(0,s.size() - kmp[kmp.size()-1]) + str;
        
    }
};