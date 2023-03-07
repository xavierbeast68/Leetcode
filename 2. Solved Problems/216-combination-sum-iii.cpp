//* https://leetcode.com/problems/combination-sum-iii/description/
//* https://www.youtube.com/watch?v=77KQifr--ek

class Solution {
public:
    vector<vector<int>> answer;

    void dfs(vector<int>& temp, int moves , int target, int ind){
        if(moves == 0){
            if(target == 0){
                answer.push_back(temp);
            }
            return;
        }

        for(int i = ind; i <= 9; ++i){
            if(i > target){
                break;
            }

            temp.push_back(i);
            dfs(temp,moves-1, target-i, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {

        if(n < k || n > 46){
            return answer;
        }

        vector<int> temp;
        dfs(temp,k, n, 1);

        return answer;
    }
};