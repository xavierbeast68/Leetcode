//* https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/description/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int cntOne = 0;
        for(auto i : nums){
            if(i == 1){
                cntOne++;
            }
        }
        if(cntOne > 0){
            return n-cntOne;
        }

        int minSteps = INT_MAX;
        for(int i = 0; i < n; ++i){
            int currGcd = 0;
            for(int j = i; j < n; ++j){
                currGcd = __gcd(currGcd, nums[j]);

                if(currGcd == 1){
                    minSteps = min(minSteps, (j-i)+(n-1));
                    break;
                }
            }
        }

        return (minSteps == INT_MAX? -1 : minSteps);
    }
};