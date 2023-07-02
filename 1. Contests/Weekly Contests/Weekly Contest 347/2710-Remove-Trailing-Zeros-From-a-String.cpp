//* https://leetcode.com/problems/remove-trailing-zeros-from-a-string/

class Solution {
public:
    string removeTrailingZeros(string num) {
        int n = num.size();
        int ind = n-1;
        while(ind >= 0 && num[ind] == '0'){
            ind--;
        }
        if(ind == -1){
            return "";
        }
        
        return num.substr(0, ind+1);
    }
};