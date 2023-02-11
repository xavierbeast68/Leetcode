//* https://leetcode.com/problems/valid-anagram/description/
//* https://leetcode.com/problems/valid-anagram/submissions/896145515/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }

        map<char,int> mp;
        for(char ch : s){   // O(n)
            mp[ch]++;
        }
        for(char ch : t){   // O(n)
            if(mp.find(ch) == mp.end()){  // O(log n)
                return false;
            }
            mp[ch]--;
            if(mp[ch]==0){
                mp.erase(ch);   // O(log n)
            }
        }
        if(mp.size() > 0){
            return false;
        }
        return true;
    }
}; // time compleixty -> O(n log n)