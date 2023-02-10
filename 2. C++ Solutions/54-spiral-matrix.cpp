//* https://leetcode.com/problems/spiral-matrix/
//* https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form/
//* https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int startRow = 0, endRow = matrix.size()-1;
        int startCol = 0, endCol = matrix[0].size()-1;

        while(startRow <= endRow && startCol <= endCol){

            // Top
            for(int col = startCol; col <= endCol; col++){
                ans.push_back(matrix[startRow][col]);
            }

            // Right
            for(int row = startRow+1; row <= endRow; row++){
                ans.push_back(matrix[row][endCol]);
            }

            // Bottom
            for(int col = endCol-1; col >= startCol; col--){
                if(startRow == endRow){
                    break;
                }
                ans.push_back(matrix[endRow][col]);
            }

            // Left
            for(int row = endRow-1; row > startRow; row--){
                if(startCol == endCol){
                    break;
                }
                ans.push_back(matrix[row][startCol]);
            }

            // Updations->
            startRow++, endRow--;
            startCol++, endCol--;
        }

        return ans;
    }
};