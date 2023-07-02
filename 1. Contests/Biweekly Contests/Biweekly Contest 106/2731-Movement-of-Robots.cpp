//* https://leetcode.com/problems/movement-of-robots/
//* https://www.youtube.com/watch?v=fxhviazRNsE

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();

        // final points of each robot
        for(int i = 0; i < n; i++){
            
            if(s[i] == 'R'){
                nums[i] += d; 
            }
            else{
                nums[i] -= d;
            }
        }

        // using typical prefix approach->
        sort(nums.begin(), nums.end());
        long long ans = 0, prefSum = 0;
        int mod = 1e9+7;
        for(int i = 0; i < n; i++){
            
            ans =  (ans + i * (long long)(nums[i]) - prefSum) % mod;
            prefSum += nums[i] % mod;
        }

        return (int)ans;
    }
};