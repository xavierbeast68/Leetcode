//* https://leetcode.com/problems/minimum-cost-to-make-all-characters-equal/description/

class Solution {
public:
    long long minimumCost(string s) {
        int n = s.size();
        
        if(n == 1){
            return 0;
        }
        
        long long ans = 0;
        
        for(int i = 1; i < n; i++){
            long long fl = 0, fr = 0;
            if(s[i] != s[i-1]){
                fl = i;
                fr = (n-i);
            }
            
            ans += (long long)min(fl, fr);
        }
        
        return ans;
    }
};