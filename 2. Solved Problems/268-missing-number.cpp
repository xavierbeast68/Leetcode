//* https://leetcode.com/problems/missing-number/description/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int p=-1;
        // for(int i=0;i<nums.size();i++)
        // {
        //     if(i!=nums[i])
        //     {
        //         p=i;
        //         break;
        //     }
        // }
        // if(p==-1) {return nums.size();}
        // else {return p;}

        int temp = 0, j = 1, xr = 0;
        for(int i : nums){
            xr ^= i;
            temp ^= j;
            j++;
        }
        return xr ^ temp;
    }
};