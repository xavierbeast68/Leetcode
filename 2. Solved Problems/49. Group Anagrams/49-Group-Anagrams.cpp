//* https://leetcode.com/problems/group-anagrams/
//* https://leetcode.com/problems/group-anagrams/editorial/
//* https://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together/
//* https://www.youtube.com/watch?v=vzdNOK2oB2E&ab_channel=NeetCode

class Solution {
public:
    vector<int> get_hash(string s){
        vector<int> h(26, 0);
        for(char ch : s){
            h[ch-'a']++;
        }
        return h;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> h;
        for(string s : strs){
            h[get_hash(s)].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto i : h){
            ans.push_back(i.second);
        }

        return ans;
    }
};