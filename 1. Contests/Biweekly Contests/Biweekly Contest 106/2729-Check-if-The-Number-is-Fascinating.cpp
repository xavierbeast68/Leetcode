//* https://leetcode.com/problems/check-if-the-number-is-fascinating/

class Solution {
public:
    bool isFascinating(int n) {
        int n2 = 2*n;
        int n3 = 3*n;
        
        string s = to_string(n) + to_string(n2) + to_string(n3);
        
        unordered_map<char, int> mp;
        for(char ch : s){
            mp[ch]++;
            
            if(ch == '0' || mp[ch] > 1){
                return false;
            }
        }
        
        return true;
    }
};