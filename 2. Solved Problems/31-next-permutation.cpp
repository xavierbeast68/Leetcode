//* https://leetcode.com/problems/next-permutation/
//* https://leetcode.com/problems/next-permutation/submissions/896756194/
//* https://www.youtube.com/watch?v=LuLCLgMElus

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // using next_permutation() function
        // next_permutation(begin(nums), end(nums));
        // not recommended
        int N = nums.size();
        if(N == 1){
            return;
        }
        
        int i = N-2, ind1 = -1;
        while(i >= 0 && ind1 == -1){
            if(nums[i] < nums[i+1]){
                ind1 = i;
            }
            i--;
        }
        if(ind1 == -1){
            reverse(begin(nums), end(nums));
            return;
        }
        
        i = N-1;
        int ind2 = -1;
        while(i >= 0 && ind2 == -1){
            if(nums[i] > nums[ind1]){
                ind2 = i;
            }
            i--;
        }
        
        // swapping->
        int temp = nums[ind1]; nums[ind1] = nums[ind2]; nums[ind2] = temp;
        
        reverse(nums.begin() + (ind1 + 1), nums.end());
        
        return;
    }
};