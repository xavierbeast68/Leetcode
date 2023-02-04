class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int start =0 , end = len-1;

        while(start <= end){
            int mid = start + (end-start)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target)
            {
                if(target <= nums[end] && target < nums[start] && nums[mid] > nums[end]){
                    start = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
            else{
                if(nums[end] < target && nums[start] <= target && nums[start] > nums[mid]){
                    end = mid - 1;
                }
                else{
                    start = mid + 1;
                }
            }
        }
        return -1;
    }
};