//* https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/
//* https://www.youtube.com/watch?v=UVV9EzsXGwo&ab_channel=PrakharAgrawal

class Solution {
public:
    bool isPossible(vector<int>&nums, int maxDiff, int p){
        int cnt = 0;
        int n = nums.size();
        for(int i = 1; i < n; ++i){
            if(nums[i]-nums[i-1] <= maxDiff){
                cnt++; // p--;
                i++;
            }
        }

        return cnt >= p; // p <= 0
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        int low = 0, high = nums[n-1] - nums[0];
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(isPossible(nums, mid, p)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};