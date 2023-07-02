//* https://leetcode.com/problems/lexicographically-smallest-palindrome/description/

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.length();
        for(int i = 0; i < n/2; i++){
            if(s[i] < s[n-i-1]){
                s[n-i-1] = s[i];
            }
            else if(s[i] > s[n-i-1]){
                s[i] = s[n-i-1];
            }
        }
        
        return s;
    }
};