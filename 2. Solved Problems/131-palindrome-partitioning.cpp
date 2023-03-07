//* https://www.youtube.com/watch?v=WBgsABoClE0&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=17
//* https://leetcode.com/problems/palindrome-partitioning/

class Solution {
public:
    void partition(vector<vector<string>>& ans, string s, vector<string>& temp){
        if(s.length() == 0){
            ans.push_back(temp);
            return;
        }
        for(int i = 1; i <= s.length(); ++i){
            string part1 = s.substr(0, i);
            string part2 = s.substr(i);
            
            if(isPalindrome(part1)){
                temp.push_back(part1);
                partition(ans, part2, temp);
                temp.pop_back();
            }
        }
    }
    bool isPalindrome(string s){
        int i = 0, j = s.length()-1;
        string temp = s;
        while(i <= j){
            char ch = temp[i];
            temp[i] = temp[j];
            temp[j] = ch;
            i++, j--;
        }
        return (s.compare(temp) == 0);
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        partition(ans, s, temp);
        return ans;
    }
};