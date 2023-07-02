//* https://leetcode.com/problems/find-the-longest-semi-repetitive-substring/

class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.length();
        int maxLen = 1;
        
        for(int i = 0; i < n; i++){
            
            int tempLen = 1;
            int cntPair = 0;
            
            for(int j = i + 1; j < n; j++){
                
                if(s[j-1] == s[j]){
                    cntPair++;
                }
                
                if(cntPair > 1){
                    break;
                }
                
                tempLen++;
            }
            maxLen = max(maxLen, tempLen);
        }
        
        return maxLen;
    }
};