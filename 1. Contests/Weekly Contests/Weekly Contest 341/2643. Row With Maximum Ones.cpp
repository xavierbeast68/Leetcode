//* https://leetcode.com/problems/row-with-maximum-ones/description/

class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int  m = mat.size();
        int  n = mat[0].size();
        vector<int> ans;
        int max_count = 0, maxRow = 0;
        
        for(int i = 0; i < m; ++i){
            int curr_count = 0;
            for(int j = 0; j < n; ++j){
                if(mat[i][j] == 1){
                    curr_count++;
                }
            }
            
            if(curr_count > max_count){
                max_count = curr_count;
                maxRow = i;
            }
        }
        
        ans.push_back(maxRow);
        ans.push_back(max_count);
        
        return ans;
    }
};