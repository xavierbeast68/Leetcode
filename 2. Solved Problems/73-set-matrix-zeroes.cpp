//* https://leetcode.com/problems/set-matrix-zeroes/description/
//* https://leetcode.com/problems/set-matrix-zeroes/solutions/
//* https://leetcode.com/problems/set-matrix-zeroes/solutions/177436/set-matrix-zeroes/

class Solution {
public:
    void  zero_function(vector<vector<int>>& matrix, int zeroRow, int zeroCol, int rows, int cols){
        for(int i = 0 ; i < cols; i++){
            matrix[zeroRow][i] = 0;
        }
        for(int i = 0 ; i < rows; i++){
            matrix[i][zeroCol] = 0;
        }
    }
    // void dbg(multimap<int,int>& mp){
    //     for(auto& i: mp){
    //         cout<<i.first<<" "<<i.second<<endl;
    //     }
    // }
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(); // m
        int cols = matrix[0].size(); // n
        multimap<int,int> zero_row;

        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(matrix[i][j] == 0){
                    zero_row.insert({i,j});
                }
            }
        }
        // dbg(zero_row);
        for(auto& i : zero_row){
            zero_function(matrix, i.first, i.second, rows, cols);
        }
    }
};