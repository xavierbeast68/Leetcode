//* https://leetcode.com/problems/subsets/description/

class Solution {
public:
    void dfs(vector<int>& temp, vector<vector<int>>& ans, vector<int>& nums, int i){
        if(i == nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        dfs(temp, ans, nums, i+1);
        temp.pop_back();
        dfs(temp, ans, nums, i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        dfs(temp, ans, nums, 0);
        return ans;
    }
};