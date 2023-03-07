//* https://leetcode.com/problems/combination-sum-ii/
//* https://www.youtube.com/watch?v=G1fRTGRxXU8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=9&ab_channel=takeUforward

class Solution {
public:
    vector<vector<int>> answer;
    void dfs(vector<int>& temp, vector<int>& candidates, int target, int ind){
        if(target == 0){
            answer.push_back(temp);
            return;
        }

        for(int i = ind ; i < candidates.size() ; i++){
            if(i > ind && candidates[i] == candidates[i-1]){
                continue;
            }
            if(candidates[i] > target){
                break;
            }

            temp.push_back(candidates[i]);
            dfs(temp, candidates, target - candidates[i], i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(begin(candidates), end(candidates));
        dfs(temp, candidates, target, 0);
        return answer;
    }
};