//* https://leetcode.com/problems/minimize-string-length/

class Solution {
public:
    int minimizedStringLength(string s) {
        int n = s.length();
        
        if(n == 1){
            return 1;
        }
        
        unordered_map<char, int> mp;
        // int sz = n;
        for(int i = 0; i < n; i ++){
            // if(s[i-1] == s[i]){
            //     sz--;
            // }
            
            mp[s[i]] = 1;
        }
        
        return mp.size();
    }
};