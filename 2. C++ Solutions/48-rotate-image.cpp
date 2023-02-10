//* https://leetcode.com/problems/rotate-image/
//* https://leetcode.com/problems/rotate-image/submissions/895606359/
//* https://leetcode.com/problems/rotate-image/solutions/1037232/rotate-image/


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int startRow = 0, endRow = n-1;
        int startCol = 0, endCol = n-1;

        for(int level = 1; level <= n/2 ; level++){

                int counter = 0;
                while(counter < (endRow - startRow)){
                    int temp = matrix[startRow][startCol + counter];
                    matrix[startRow][startCol + counter] = matrix[endRow - counter][startCol];
                    matrix[endRow - counter][startCol] = matrix[endRow][endCol - counter];
                    matrix[endRow][endCol - counter] = matrix[startRow + counter][endCol];
                    matrix[startRow + counter][endCol] = temp;

                    counter++;
                }

                startRow++, endRow--;
                startCol++, endCol--;
        }
    }
};