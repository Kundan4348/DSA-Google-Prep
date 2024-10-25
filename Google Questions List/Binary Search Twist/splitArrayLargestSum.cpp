// minimize the maximum
//when talking about minimize the maximum then we cannot increase this more than the maxumum which is mid

https://leetcode.com/problems/split-array-largest-sum/description/?envType=company&envId=google&favoriteSlug=google-six-months&role=full-stack&difficulty=HARD


class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(),nums.end()), r = 0;
        r = accumulate(nums.begin(),nums.end(),0);
        int res = -1;
        while(l<=r){
            
            int mid = (l + r)/2;
            
            int count = 1;
            int sum = 0;
            for(int i=0;i<nums.size();++i) {
                if(sum + nums[i] <= mid){
                    sum = sum + nums[i];
                } else {
                    sum = nums[i];
                    count++;
                }
            }
            
            if(count > k){
                l = mid+1;
            } else {
                res = mid;
                r = mid-1;
            }
        }
        
        return l; //return res (same)
    }
};