//* https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/description/

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int sum = 0, el = nums[nums.size()-1];
        for(int i = 1; i <= k; ++i){
            sum += el;
            el += 1;
        }
        
        return sum;
    }
};