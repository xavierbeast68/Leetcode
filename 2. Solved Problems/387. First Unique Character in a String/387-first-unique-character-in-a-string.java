//* https://leetcode.com/problems/first-unique-character-in-a-string/description/

class Solution {
    public:
        int firstUniqChar(string s) {
            queue<char> q;
            int freq[26] = {0};
            for(int i = 0; i < s.length(); ++i){
                char ch = s[i];
                q.push(ch);
                freq[ch - 'a']++;
    
                while(!q.empty() && freq[q.front() - 'a'] > 1){
                    q.pop();
                }
            }
    
            if(q.empty()){
                return -1;
            }
    
            else{
                return s.find(q.front());
            }
        }
    };