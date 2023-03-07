//* https://leetcode.com/problems/valid-palindrome/description/
//* https://leetcode.com/problems/valid-palindrome/submissions/896130247/

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length()-1;
        if(s.length() == 1){
            return true;
        }
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while(i <= j){
            while(i<=j && !((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))){
                i++;
            }
            while(i<=j && !((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9'))){
                j--;
            }
            if(i<=j && s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};