//* https://leetcode.com/problems/find-the-maximum-divisibility-score/description/

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int cnt = 0;
        int ans = divisors[0];
        
        for(auto i : divisors){
            int currCnt = 0;
            for(auto j : nums){
                if(j%i == 0){
                    currCnt++;
                }
            }
            
            if(currCnt == cnt){
                ans = min(ans, i);
            }
            if(currCnt > cnt){
                cnt = currCnt;
                ans = i;
            }
        }
        
        return ans;
    }
};