//* https://leetcode.com/problems/neither-minimum-nor-maximum/

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || n == 2){
            return -1;
        }
        
        sort(nums.begin(), nums.end());
        
        return nums[1];
    }
};