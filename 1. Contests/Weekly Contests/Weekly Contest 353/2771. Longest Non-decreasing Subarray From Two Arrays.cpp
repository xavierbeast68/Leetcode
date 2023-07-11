//* https://leetcode.com/problems/longest-non-decreasing-subarray-from-two-arrays/
//* https://www.youtube.com/watch?v=diIBKVks7OE
//* https://www.youtube.com/watch?v=R3YJP_gxZqc

class Solution {
public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>> dp(n, vector<int>(2, 1));
        int ans = 1;
        
        for(int i = 1; i < n; i++){
            if(nums1[i] >= nums1[i-1]){
                dp[i][0] = max(dp[i][0], 1 + dp[i-1][0]);
            }
            
            if(nums1[i] >= nums2[i-1]){
                dp[i][0] = max(dp[i][0], 1 + dp[i-1][1]);
            }
            
            if(nums2[i] >= nums1[i-1]){
                dp[i][1] = max(dp[i][1], 1 + dp[i-1][0]);
            }
            
            if(nums2[i] >= nums2[i-1]){
                dp[i][1] = max(dp[i][1], 1 + dp[i-1][1]);
            }
            
            ans = max(ans, dp[i][0]);
            ans = max(ans, dp[i][1]);
        }
        
        return ans;
    }
};