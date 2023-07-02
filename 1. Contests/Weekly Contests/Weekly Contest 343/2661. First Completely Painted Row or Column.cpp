//* https://leetcode.com/problems/first-completely-painted-row-or-column/description/

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        map<int,int> mp;
        for(int i = 0; i < m*n; i++){
            mp[arr[i]] = i;
        }
        
        // for(auto i : mat){
        //     for(auto j : i){
        //         cerr << j << " ";
        //     }
        //     cout << endl;
        // }

        int row = INT_MAX;
        // checking row
        for(int i = 0; i < m; i++){
            int maxCol = -1;
            for(int j = 0; j < n; j++){
                maxCol = max(maxCol, mp[mat[i][j]]);
            }
            row = min(row, maxCol);
        }
        
        int col = INT_MAX;
        // checking col
        for(int j = 0; j < n; j++){
            int maxRow = -1;
            for(int i = 0; i < m; i++){
                maxRow = max(maxRow, mp[mat[i][j]]);
            }
            col = min(col, maxRow);
        }
        
        return min(row, col);
    }
};