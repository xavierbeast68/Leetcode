//* https://leetcode.com/problems/word-search/description/
//* https://www.youtube.com/watch?v=pfiQ_PS1g8E
//* https://www.youtube.com/watch?v=hPyR1un7_hw

class Solution {
public:
    // used to track the cells visited
    // set<pair<int,int>> path;

    bool present(vector<vector<char>>& board, string& word, int r, int c, int i){
        
        // i takes note of matched letters visited
        // if we found the word
        if(i == word.length()){
            return true;
        }

        // pair<int,int> x = make_pair(r,c);
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() // r,c gets out of bounds
            || word[i] != board[r][c] // current letter is not the corresponding letter of the word
            // || path.find(x) != path.end()
            ) { // cell already visited
                return false;
        }

        // else->
        // path.insert(x);
        board[r][c] = '#';
        bool res = (present(board, word, r-1, c, i+1) || // checking upward 
                    present(board, word, r+1, c, i+1) || // checking downward
                    present(board, word, r, c+1, i+1) || // checking rightward
                    present(board, word, r, c-1, i+1) ); // checking leftward
        // path.erase(path.find(x));
        board[r][c] = word[i];
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(present(board, word, r, c, 0)){
                    return true;
                }
            }
        }

        return false;
    }
};