//* https://leetcode.com/problems/combination-sum/
//* https://www.youtube.com/watch?v=OyZFFqQtu98&ab_channel=takeUforward

class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& temp, vector<int>& candidates, int target, int ind){
        if(ind == candidates.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            return;
        }
        
        if(candidates[ind] <= target){
            temp.push_back(candidates[ind]);
            dfs(temp, candidates, target - candidates[ind], ind);
            temp.pop_back(); 
        }
        dfs(temp, candidates, target, ind + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        
        // remove duplicates
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

        dfs(temp, candidates, target, 0);
        return ans;
    }
};