//* https://leetcode.com/problems/diagonal-traverse/description/
//* https://leetcode.com/problems/diagonal-traverse/submissions/895537451/
//* https://leetcode.com/problems/diagonal-traverse/solutions/459889/diagonal-traverse/
//* https://www.youtube.com/watch?v=FH9BxnzumVo

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int rows = mat.size();
        int cols = mat[0].size();
        int curr_row = 0, curr_col = 0;
        bool going_up = true;

        while(ans.size() != rows*cols){

            if(going_up){
                // while being inside the grid
                while(curr_row >= 0 && curr_col < cols){
                    ans.push_back(mat[curr_row][curr_col]);

                    curr_row--;
                    curr_col++;
                }

                // gets out of the upper right corner of the grid
                if(curr_col == cols){
                    curr_row += 2;
                    curr_col--;
                }

                // gets out of the top of the grid where curr_col < cols
                else{
                    curr_row++;
                }

                going_up = false;
            }

            // going down
            else{
                while(curr_row < rows && curr_col >= 0){
                    ans.push_back(mat[curr_row][curr_col]);

                    curr_col--;
                    curr_row++;
                }

                // getting out from bottom-left side
                if(curr_row == rows){
                    curr_col += 2;
                    curr_row--;
                }

                // getting outside of grid from left-side where curr_row < rows
                else{
                    curr_col++;
                }

                going_up = true;
            }
        }

        return ans;
    }
};