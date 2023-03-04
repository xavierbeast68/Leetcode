//* https://leetcode.com/problems/n-queens/description/
//* https://www.youtube.com/watch?v=9wEwqNdOAVQ&t=1256s&ab_channel=CodeHelp-byBabbar
//* https://www.youtube.com/watch?v=i05Ju7AftcM&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=14&ab_channel=takeUforward
//* https://takeuforward.org/data-structure/n-queen-problem-return-all-distinct-solutions-to-the-n-queens-puzzle/


class Solution {
public:
    void addSolution(vector<vector<string>>& ans, vector<vector<int>>& board){
        vector<string> helper;
        for(int row = 0; row < board.size(); row++){
            string temp = "";
            for(int col = 0; col < board[0].size(); col++){
                if(board[row][col] == 1){
                    temp = temp + 'Q';
                }
                else{
                    temp = temp + '.';
                }
            }
            helper.push_back(temp);
        }
        ans.push_back(helper);
    }
    bool isSafe(vector<vector<int>>& board, int col, int row, int n, vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal){

        if(leftRow[row] == 1){
            return false;
        }
        if(lowerDiagonal[row+col] == 1){
            return false;
        }
        if(upperDiagonal[(n-1) + (col-row)] == 1){
            return false;
        }

        return true;
    }
    void solve(vector<vector<string>>& ans, vector<vector<int>>& board, int n , int col, vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal){
        if(col == n){
            addSolution(ans, board);
            return;
        }
        
        for(int row = 0; row < n ; ++row){
            if(isSafe(board, col , row, n, leftRow, lowerDiagonal, upperDiagonal)){
                board[row][col] = 1;
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[(n-1) + (col-row)] = 1;
                solve(ans, board, n, col + 1, leftRow, lowerDiagonal, upperDiagonal);
                board[row][col] = 0;
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[(n-1) + (col-row)] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<string>> ans;
        vector<int> leftRow(n,0), lowerDiagonal(2 * n -1, 0), upperDiagonal(2 * n -1, 0);
        solve(ans, board, n, 0, leftRow, lowerDiagonal, upperDiagonal);
        return ans;
    }
};

//* without using maps
// class Solution {
// public:
//     void addSolution(vector<vector<string>>& ans, vector<vector<int>>& board){
//         vector<string> helper;
//         for(int row = 0; row < board.size(); row++){
//             string temp = "";
//             for(int col = 0; col < board[0].size(); col++){
//                 if(board[row][col] == 1){
//                     temp = temp + 'Q';
//                 }
//                 else{
//                     temp = temp + '.';
//                 }
//             }
//             helper.push_back(temp);
//         }
//         ans.push_back(helper);
//     }
//     bool isSafe(vector<vector<int>>& board, int col, int row, int n){
//         int tempRow, tempCol;
        
//         tempCol = col;
//         while(tempCol >= 0){
//             if(board[row][tempCol]){
//                 return false;
//             }
//             tempCol--;
//         }

//         tempCol = col, tempRow = row;
//         while(tempRow >= 0 && tempCol >= 0){
//             if(board[tempRow][tempCol]){
//                 return false;
//             }
//             tempCol--, tempRow--;
//         }

//         tempCol = col, tempRow = row;
//         while(tempRow < n & tempCol >= 0){
//             if(board[tempRow][tempCol]){
//                 return false;
//             }
//             tempRow++, tempCol--;
//         }

//         return true;
//     }
//     void solve(vector<vector<string>>& ans, vector<vector<int>>& board, int n , int col){
//         if(col == n){
//             addSolution(ans, board);
//             return;
//         }
        
//         for(int row = 0; row < n ; ++row){
//             if(isSafe(board, col , row, n)){
//                 board[row][col] = 1;
//                 solve(ans, board, n, col + 1);
//                 board[row][col] = 0;
//             }
//         }
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<int>> board(n, vector<int>(n, 0));
//         vector<vector<string>> ans;
//         solve(ans, board, n, 0);
//         return ans;
//     }
// };


//* Striver's Code->
// class Solution {
//     public:
//         bool isSafe1(int row, int col, vector < string > board, int n) {
//             // check upper element
//             int duprow = row;
//             int dupcol = col;

//             while (row >= 0 && col >= 0) {
//                 if (board[row][col] == 'Q')
//                     return false;
//                 row--;
//                 col--;
//             }

//             col = dupcol;
//             row = duprow;
//             while (col >= 0) {
//                 if (board[row][col] == 'Q')
//                     return false;
//                 col--;
//             }

//             row = duprow;
//             col = dupcol;
//             while (row < n && col >= 0) {
//                 if (board[row][col] == 'Q')
//                     return false;
//                 row++;
//                 col--;
//             }
//             return true;
//         }

//     public:
//         void solve(int col, vector < string > & board, vector < vector < string >> & ans, int n) {
//             if (col == n) {
//                 ans.push_back(board);
//                 return;
//             }
//             for (int row = 0; row < n; row++) {
//                 if (isSafe1(row, col, board, n)) {
//                     board[row][col] = 'Q';
//                     solve(col + 1, board, ans, n);
//                     board[row][col] = '.';
//                 }
//             }
//         }

//     public:
//         vector < vector < string >> solveNQueens(int n) {
//             vector < vector < string >> ans;
//             vector < string > board(n);
//             string s(n, '.');
//             for (int i = 0; i < n; i++) {
//                 board[i] = s;
//             }
//             solve(0, board, ans, n);
//             return ans;
//         }
// };