//* https://leetcode.com/problems/longest-common-prefix/description/
//* https://leetcode.com/problems/longest-common-prefix/solutions/127449/longest-common-prefix/
//* https://leetcode.com/problems/longest-common-prefix/submissions/896457892/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }
        string prefix = strs[0];

        for(string s : strs){
            while(s.find(prefix) != 0){
                prefix = prefix.substr(0, prefix.length()-1);
                if(prefix.length() == 0){
                    return "";
                }
            }
        }

        return prefix;
    }
};