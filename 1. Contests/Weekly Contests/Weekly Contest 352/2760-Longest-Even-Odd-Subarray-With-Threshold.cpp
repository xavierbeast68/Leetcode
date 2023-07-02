//* https://leetcode.com/problems/longest-even-odd-subarray-with-threshold/

class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int n = nums.size();
        int j = 0;
        int len = 0, tempLen = 0;
        int oddEven = 0; // 0->even, 1->odd
        while(j < n){
            
            if(nums[j] <= threshold && nums[j]%2 == oddEven){
                oddEven = oddEven? 0 : 1;
                tempLen++;
                
            }
            else{
                if(nums[j] > threshold){
                    tempLen = 0;
                    oddEven = 0;
                }
                else{
                    if(nums[j]%2 == 0){
                        oddEven = 1;
                        tempLen = 1;
                    }
                    else{
                        tempLen = 0;
                        oddEven = 0;
                    }
                }
            }
            
            len = max(len, tempLen);
            j++;
            
        }
        
        return len;
    }
};