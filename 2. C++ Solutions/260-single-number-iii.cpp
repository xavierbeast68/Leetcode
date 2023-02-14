//* https://leetcode.com/problems/single-number-iii/description/
//* https://leetcode.ca/2016-08-16-260-Single-Number-III/
//* https://leetcode.com/problems/single-number-iii/submissions/897771797/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp = 0;
        for(int i : nums){
            temp = temp ^ i;
        }
        int result = temp;
        int p = 1;
        while((temp & 1) == 0){
            temp >>= 1;
            p++;
        }
        int mask = 1 << (p-1);
        int a = 0, b=0;
        for(int i : nums){
            if(i & mask){
                a ^= i;
            }
            // else {
            //     b ^= i;
            // }
        }
        b = a ^ result;
        vector<int> ans{min(a, b), max(a,b)};
        return ans;
    }
};