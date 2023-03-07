//* https://leetcode.com/problems/number-of-1-bits/description/
//* https://leetcode.com/problems/number-of-1-bits/submissions/897745680/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // int count = 0;
        // while(n > 0){
        //     if(n & 1){
        //         count++;
        //     }
        //     n >>= 1;
        // }
        // return count;

        return __builtin_popcountll(n);
    }
};