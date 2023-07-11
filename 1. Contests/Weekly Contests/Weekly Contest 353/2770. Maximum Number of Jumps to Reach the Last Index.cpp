//* https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/
//* https://youtu.be/ME3F0Nf0660

class Solution {
public:
    // int jumps;
//     void rec(int i, int n, vector<int> nums, int target, int curr){
//         if(i == n-1){
//             jumps = max(jumps, curr);
//             return;
//         }
        
//         for(int j = i+1; j < n; j++){
//             long long diff = abs(1ll* nums[j] - 1*llnums[i]);
//             if(diff <= target){
//                 rec(j, n, nums, target, curr+1);
//             }
//         }
//     }
    int maximumJumps(vector<int>& nums, int target) {
        //* Recursive method-> TLE
        // jumps = INT_MIN;
        // rec(0, nums.size(), nums, target, 0);
        // return (jumps == INT_MIN ? -1 : jumps);
        
        
        int n = nums.size();
        vector<int> jumps(n, 0);
        jumps[0] = 1; // starting from oth index
        for(int i = 0; i < n; i++){
            // if jumps[i] > 0, only then we can reach the ith index and can route to other via this ith index
            if(jumps[i] > 0){

                // from this ith index, how many other jth indexes we can reach
                for(int j = i+1; j < n; j++){
                
                    long long diff = nums[j];
                    diff -= nums[i];
                    diff = abs(diff);
                    if(diff <= target){
                        
                        jumps[j] = max(jumps[j], jumps[i]+1);
                    }
                }
            }
        }
        
        return jumps[n-1] > 0 ? jumps[n-1]-1 : -1;
    }
};