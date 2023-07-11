//* https://leetcode.com/problems/longest-alternating-subarray/
//* https://youtu.be/iUAv06QgJhY

class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> diff(n-1);
        for(int i = 0; i < n-1; i++){
            diff[i] = nums[i+1] - nums[i];
        }
        
        int j = 0, len = 0, maxLen = 0, pole = 1;
        while(j < n-1){
            
            if(diff[j] == pole){
                len++;
                maxLen = max(maxLen, len);
                pole = (pole==1? -1 : 1);
            }
            else{
                pole = 1;
                len = 0;
                if(diff[j] == pole){
                    continue;
                }
            }
            
            j++;
        }
        
        return maxLen > 0?(maxLen+1) : -1;
    }
};