//maximize the minimum
// when talking about maximize the minimum then we can go a little further than mid but only one step

//https://leetcode.com/problems/divide-chocolate/
class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int lo = 1,hi=accumulate(sweetness.begin(),sweetness.end(),0);
       while(lo<hi){

            int mid = (lo+hi+1)/2;
            int parts = 1;
            int currSum = 0;
            for(int i=0;i<sweetness.size();++i){
                currSum+=sweetness[i];
                if(currSum >= mid){
                    currSum = 0;
                    parts++;
                }
            }

            if(parts>k+1){
                lo = mid;
            } else {
                hi = mid-1;
            }
       }

       return lo;
    }
};  