//* https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums), end(nums));
        for(int i=0; i<n-1; i++){
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
    }
};