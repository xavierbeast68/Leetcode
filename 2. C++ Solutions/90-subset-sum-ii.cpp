//* https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    void dfs(vector<int>& temp, vector<vector<int>>& answer, vector<int>& nums, int ind){
        answer.push_back(temp);
        
        for(int i = ind ; i < nums.size() ; i++){
            if(i > ind && nums[i] == nums[i-1]){
                continue;
            }
            
            temp.push_back(nums[i]);
            dfs(temp, answer, nums, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        dfs(temp, answer, nums, 0);

        return answer;
    }
};