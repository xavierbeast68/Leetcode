//* https://leetcode.com/problems/semi-ordered-permutation/

class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        
        int n = nums.size();
        // Brute->
//         int maxi = 0, maxPos = -1;
//         int mini = 51, minPos = -1;
        
//         for(int i = 0; i < n; i++){
//             if(nums[i] < mini){
//                 mini = nums[i];
//                 minPos = i;
//             }
//             if(nums[i] > maxi){
//                 maxi = nums[i];
//                 maxPos = i;
//             }
//         }
        
//         int lastInd = n-1;
//         int swaps = (minPos) + (lastInd - maxPos);
        
//         if(maxPos < minPos){
//             swaps -= 1;
//         }
        
        int minPos = find(begin(nums), end(nums), 1) - nums.begin();
        int maxPos = find(begin(nums), end(nums), n) - nums.begin();
        
        int lastInd = n-1;
        
        int swaps = (minPos) + (lastInd - maxPos);
        // cout << maxPos << " " << minPos << endl;
        if(maxPos < minPos){
            swaps -= 1;
        }
        
        return swaps;
    }
};