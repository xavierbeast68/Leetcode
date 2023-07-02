//* https://leetcode.com/problems/maximum-strength-of-a-group/description/

class Solution {
public:
    long long product(vector<int>& nums){
        long long prod = nums[0];
        int n = nums.size();
        for(int i = 1; i < n; i++){
            prod *= nums[i];
        }
        return prod;
    }
    long long maxi;
    void dfs(vector<int>& nums, int ind, vector<int>& temp){
        if(ind < 0){
            if(temp.size() == 0){
                return;
            }
            
            long long prod = product(temp);
            
            if(maxi < prod){
                maxi = prod;
            }
            return;
        }
        
        // nottake
        dfs(nums, ind-1, temp);
        // Take
        temp.push_back(nums[ind]);
        dfs(nums, ind-1, temp);
        temp.pop_back();
    }
    long long maxStrength(vector<int>& nums) {
        maxi = LONG_MIN;
        
        if(nums.size() == 1){
            return nums[0];
        }
        
        
        int n = nums.size();
        vector<int> temp;
        dfs(nums, n-1, temp);
        
        
        return maxi;
    }
};