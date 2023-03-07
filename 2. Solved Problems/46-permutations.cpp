//* https://leetcode.com/problems/permutations/description/
//! https://www.youtube.com/watch?v=YK78FU5Ffjw&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=12&ab_channel=takeUforward
//* Space Optimised Approach->
//! https://www.youtube.com/watch?v=f2ic2Rsc9pU&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=13&ab_channel=takeUforward


// Approach -1
// class Solution {
// public:
//     vector<vector<int>> ans;
//     void dfs(vector<int> nums, vector<bool>& ticked, vector<int>& temp, int n){
//         if(temp.size() == n){
//             ans.push_back(temp);
//             return;
//         }

//         for(int i = 0 ; i < n ; ++i){
//             if(ticked[i]){
//                 continue;
//             }
//             ticked[i] = 1;
//             temp.push_back(nums[i]);
//             dfs(nums, ticked, temp, n);
//             temp.pop_back();
//             ticked[i] = 0;
//         }
//     }
//     vector<vector<int>> permute(vector<int>& nums) {
//         int n = nums.size();
//         vector<bool> ticked(n,0);
//         vector<int> temp;
//         dfs(nums, ticked, temp, n);
//         return ans;
//     }
// };

// Approach-2 (Space Optimised)
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int> nums, int n, int ind){
        if(ind == n){
            ans.push_back(nums);
            return;
        }

        for(int i = ind ; i < n ; ++i){
            swap(nums[ind], nums[i]);
            dfs(nums, n, ind + 1);
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> ticked(n,0);
        vector<int> temp;
        dfs(nums, n, 0);
        return ans;
    }
};