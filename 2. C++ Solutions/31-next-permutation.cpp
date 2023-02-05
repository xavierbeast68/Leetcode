//* https://leetcode.com/problems/next-permutation/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // using next_permutation() function
        // not recommended
        next_permutation(begin(nums), end(nums));
    }
};