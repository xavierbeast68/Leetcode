//* https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

class Solution {
public:
    vector<string> ans;
    void dfs(string temp, string digits, map<int, string>& mp, int ind){
        if(ind == digits.length()){
            ans.push_back(temp);
            return;
        }

        int d = digits[ind] - 48;
        for(int i = 0; i < mp[d].length(); ++i){
            dfs(temp + mp[d][i], digits, mp, ind + 1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0){
            return ans;
        }

        map<int, string> mp{
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}};
        dfs("", digits, mp, 0);
        return ans;
    }
};