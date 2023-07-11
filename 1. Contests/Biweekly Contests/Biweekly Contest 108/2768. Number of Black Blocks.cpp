//* https://leetcode.com/problems/number-of-black-blocks/
//* https://www.youtube.com/watch?v=mzB-Z4PP1DQ

class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        
        // {{x,y}, cnt}
        map<pair<int,int>, int> mp;
        
        for(auto it : coordinates){
            int x = it[0];
            int y = it[1];
            
            // check upper-right
            if(x-1 >= 0 && y-1 >= 0){
                mp[{x-1, y-1}]++;
            }
            
            // check upper
            if(x-1 >= 0 && y+1 < n){
                mp[{x-1, y}]++;
            }
            
            // check left
            if(y-1 >= 0 && x+1 < m){
                mp[{x, y-1}]++;
            }
            
            // update current
            if(x+1 < m && y+1 < n){
                mp[{x,y}]++;
            }
        }
        
        vector<long long> ans(5);
        
        for(auto it : mp){
            if(it.second < 5){
                ans[it.second]++;
            }
        }
        
        // number of blocks without any black cell
        long long total = 1LL* (m-1) * (n-1);
        ans[0] = total - mp.size();
        
        return ans;
    }
};