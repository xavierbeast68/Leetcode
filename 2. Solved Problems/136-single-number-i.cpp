//* https://leetcode.com/problems/single-number/
//* https://leetcode.ca/2016-04-14-136-Single-Number/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int ans=0;
        // int n=nums.size();
        // sort(nums.begin(),nums.end());
        // if(nums[0]!=nums[1]) return nums[0];
        // if(nums[n-1]!=nums[n-2]) return nums[n-1];
        // for(int i=1;i<n-1;i++)
        // {
        //     if(nums[i]!=nums[i-1] && nums[i]!=nums[i+1])
        //     {
        //         ans=nums[i];
        //         break;
        //     }
        // }
        // return ans;

        int n = 0;
        for(int i : nums){
            n ^= i;
        }
        return n;
    }
};