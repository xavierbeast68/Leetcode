//* https://leetcode.com/problems/find-a-good-subset-of-the-matrix/
//* https://www.youtube.com/watch?v=1To0OMT3WJY
//* https://www.youtube.com/watch?v=8X9FVuyBtWg

class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // 00000 - 11111-> 0 to 31 in decimal, 32 possible values
        vector<int> row_with_val(32, -1);

        for(int i = 0; i < rows; i++){
            int val = 0;
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == 1){
                    // val |= (1 << j);
                    val += (1 << j);
                }
            }

            row_with_val[val] = i;
            // doesn't matter if another row have same values, 
            // because we are only concerned with the presence of value in the matrix and not it's row number
            // so only one row is required

            // case when we get a row with all 0's, means row with sum of each col at most floor(length/2), length = 1
            if(val == 0){
                return {i};
            }
        }


        // checking pairs of vals whose sum of cols <= length/2, that is 1, as length will be 2
        for(int v1 = 0; v1 < 32; v1++){
            // value not present in any row
            if(row_with_val[v1] == -1) continue;

            // already applied in first step
            // if(v1 == 0) return {row_with_val[0]};

            for(int v2 = v1 + 1; v2 < 32; v2++){
                // value not present in any row
                if(row_with_val[v2] == -1) continue;

                // sum of cols will become 2
                if((v1 & v2) != 0) continue;

                int r1 = row_with_val[v1];
                int r2 = row_with_val[v2];
                return {min(r1, r2), max(r1, r2)};
            }
        }

        return {};
    }
};