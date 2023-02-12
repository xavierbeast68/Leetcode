//* https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
//* https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/896514549/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int n = s.length();
        int i = 0, j = 0;
        int answer = 0 ;
        while(j < n){
            mp[s[j]]++;
            
            while(i <= j && mp[s[j]] > 1){
                mp[s[i]]--;
                i++;
            }

            answer = max(answer, j - i + 1);
            j++;
        }
        return answer;
    }
};