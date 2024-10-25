// Please Refer to this solution
// https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/solutions/754682/wall-of-bricks/
// Very easy approach


class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long ans = 0;
        vector<int> diffArray;
        for(int i=0;i<nums.size();++i){
            int diff = target[i] - nums[i];
            diffArray.push_back(diff);
        }

        for(int i=0;i<nums.size();++i){
            if(i == 0){
                ans+= abs(diffArray[i]);
            } else {
                if(diffArray[i] < 0 && diffArray[i-1] < 0){
                    int currValue = abs(diffArray[i]);
                    int prevValue = abs(diffArray[i-1]);
                    ans = ans + max(0, currValue - prevValue);
                } else if(diffArray[i] >= 0 && diffArray[i-1] >= 0){
                    ans = ans + max(0, diffArray[i] - diffArray[i-1]);
                } else {
                    ans+= abs(diffArray[i]);
                }
            }
        }

        return ans;
    }
};