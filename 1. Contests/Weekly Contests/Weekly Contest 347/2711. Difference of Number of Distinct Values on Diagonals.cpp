//* https://leetcode.com/problems/difference-of-number-of-distinct-values-on-diagonals/description/

class Solution {
public:
    int calTL(int row, int col, vector<vector<int>>& grid){
        if(row == 0 || col == 0){
            return 0;
        }
        
        unordered_map<int, int> mp;
        row -= 1, col -= 1;
        while(row >= 0 && col >=0){
            mp[grid[row--][col--]] = 1;
        }
        
        return mp.size();
    }
    int calBR(int row, int col, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        
        if(row == n-1 || col == m-1){
            return 0;
        }
        
        unordered_map<int, int> mp;
        row += 1, col += 1;
        while(row < n && col < m){
            mp[grid[row++][col++]] = 1;
        }
        
        return mp.size();
    }
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> ans(n, vector<int>(m, 0));
        
        for(int row = 0; row < n; ++row){
            for(int col = 0; col < m; ++col){
                
                int topLeft = 0, bottomRight = 0;
                
                topLeft = calTL(row, col, grid);
                bottomRight = calBR(row, col, grid);
                
                ans[row][col] = abs(topLeft - bottomRight);
            }
        }
        
        return ans;
    }
};