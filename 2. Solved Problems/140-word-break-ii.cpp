//* https://leetcode.com/problems/word-break-ii/description/
//* https://www.geeksforgeeks.org/word-break-problem-using-backtracking/
//* https://www.youtube.com/watch?v=LmHWIsBQBU4

class Solution {
public:
    vector<string> ans;
    void dfs(string temp, string s, vector<string>& dict, int ind){
        if(ind == s.length()){
            ans.push_back(temp);
            return;
        }
        
        string t = "";
        for(int i = ind; i <= s.length(); ++i){
            t += s[i];
            if(isValid(dict, t)){
                dfs(temp+t+(((i+1) == s.length())?"":" "), s, dict, i+1);
            }
        }
    }
    bool isValid(vector<string>& dict, string t){
        for(int i = 0 ; i < dict.size() ; ++i){
            if(dict[i].compare(t) == 0){
                return true;
            }
        }
        return false;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        dfs("", s, wordDict, 0);
        return ans;
    }
};