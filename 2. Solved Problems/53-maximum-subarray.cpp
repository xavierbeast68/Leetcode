//* https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // using Kadane's Algorithm
        int n = nums.size();
        int maxSum = INT_MIN;
        int currSum = 0;
        int maxElement = INT_MIN; // in case all elements are -ve, we must choose least -ve.
        for (int i = 0; i < n; i++)
        {
            currSum += nums[i];

            if(currSum < 0){
                currSum = 0;
            }

            maxSum = max(maxSum, currSum);

            if(nums[i] > maxElement){
                maxElement = nums[i];
            }
        }
        return (maxSum == 0 ? maxElement : maxSum);
    }
};