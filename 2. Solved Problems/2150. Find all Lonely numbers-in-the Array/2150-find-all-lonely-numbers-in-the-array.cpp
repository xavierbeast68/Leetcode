//* https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/description/

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        vector<int> ans;

        if(nums.size() == 1){
            ans.push_back(nums[0]);
            return ans;
        }

        sort(begin(nums), end(nums));
        int n = nums.size();
        for(int i = 1; i < n-1; ++i){
            if(nums[i-1] + 1 < nums[i] && nums[i] + 1 < nums[i+1]){
                ans.push_back(nums[i]);
            }
        }
        if(nums[0] + 1 < nums[1]){
            ans.push_back(nums[0]);
        }
        if(nums[n-2] + 1 < nums[n-1]){
            ans.push_back(nums[n-1]);
        }

        return ans;
    }
};