//* https://leetcode.com/problems/lexicographically-smallest-string-after-substring-operation/

class Solution {
public:
    string change(string s, int start, int end){
        for(int i = start; i <= end; i++){
            s[i] = s[i] - 1;
        }
        return s;
    }
    string smallestString(string s) {
        int fInd = -1, flInd = -1;
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            if(s[i] == 'a'){
                fInd = i;
                while(i < n && s[i+1] == 'a'){
                    i++;
                }
                flInd = i;
                break;
            }
        }
        
        if(fInd == -1){
            return change(s, 0, n-1);
        }
        if(fInd == 0 && flInd == n-1){
            s[n-1] = 'z';
            return s;
        }
        
        
        if(fInd == 0){
            int lInd = n;
            for(int i = flInd+1; i < n; i++){
                if(s[i] == 'a'){
                    lInd = i;
                    break;
                }
            }
            string ans = "";
            ans = change(s, flInd+1, lInd-1);
            return ans;
        }
        else{
            return change(s, 0, fInd-1);
        }
    }
};