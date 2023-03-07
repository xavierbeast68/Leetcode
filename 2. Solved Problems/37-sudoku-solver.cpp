//* Sudoku Solver
//! https://www.youtube.com/watch?v=FWAIf_EVUKE&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=16
//! https://leetcode.com/problems/sudoku-solver/


class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board){
        for(int i = 0 ; i < board.size() ; ++i){
            for(int j = 0 ; j < board[0].size() ; ++j){

                if(board[i][j] == '.'){

                    for(char ch = '1' ; ch <= '9' ; ++ch){
                        
                        if(isValid(board, i, j, ch)){
                            board[i][j] = ch;

                            if(solve(board) == true){
                                return true;
                            }

                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        // already filled sudoku
        return true;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char ch){
        for(int i = 0; i < 9; ++i){

            // checking for column
            if(board[i][col] == ch){
                return false;
            }

            // checking for row
            if(board[row][i] == ch){
                return false;
            }

            // checking for 3x3 box
            if(board[3 * (row/3) + (i/3)][3 * (col/3) + (i%3)] == ch){
                return false;
            }
        }
        return true;
    }
};