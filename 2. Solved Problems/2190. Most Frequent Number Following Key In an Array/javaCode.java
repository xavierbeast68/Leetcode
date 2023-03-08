//* https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/description/

class Solution {
    public int mostFrequent(int[] nums, int key) {
        int[] arr = new int[1001];
        int ans = 0;

        for(int i = 0; i < nums.length-1; ++i){
            if(nums[i] == key){
                arr[nums[i+1]]++;
            }
        }
        int maxi = Integer.MIN_VALUE;
        for(int i = 0; i < 1001; ++i){
            if(maxi < arr[i]){
                maxi = arr[i];
                ans = i;
            }
        }
        return ans;
    }
}