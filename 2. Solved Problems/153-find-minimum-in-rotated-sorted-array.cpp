//* https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return nums[0] < nums[1] ? nums[0] : nums[1];
        }

        int minE = INT_MAX;
        int start = 0, end = n-1;

        while(start <= end){
            if(start == end){
                minE = min(minE, nums[start]);
                break;
            }
            if(start+1 == end){
                minE = min(minE, min(nums[start], nums[end]));
                break;
            }

            int mid = (start + end)/2;
            minE = min(minE, nums[mid]);

            if(nums[mid-1] > nums[mid] && nums[mid] < nums[mid+1]){
                break;
            }
            
            if(nums[mid-1] < nums[mid+1]){
                if(nums[mid-1] < nums[end]){
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            } else{
                start = mid + 1;
            }
        }

        return minE;
    }
};