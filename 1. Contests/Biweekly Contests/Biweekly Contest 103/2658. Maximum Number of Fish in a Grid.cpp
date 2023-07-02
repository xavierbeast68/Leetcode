//* https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/description/

class Solution {
public:
    int rec(vector<vector<int>>&grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()){
            return 0;   
        }
        if(grid[i][j] == 0){
            return 0;   
        }
        
        int sum = grid[i][j];
        grid[i][j] = 0;
        
        int p = rec(grid,i+1,j), q = rec(grid,i,j+1), r = rec(grid,i-1,j), s = rec(grid,i,j-1);
        
        return sum + p + q + r + s;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        
        vector<vector<int>> visited(m, vector<int>(n,0));
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] != 0){
                    ans = max (ans, rec(grid, i, j));
                }
            }
        }
        
        return ans;
    }
};