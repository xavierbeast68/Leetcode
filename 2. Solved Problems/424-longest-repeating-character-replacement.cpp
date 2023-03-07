//* https://leetcode.com/problems/longest-repeating-character-replacement/description/
//* https://leetcode.com/problems/longest-repeating-character-replacement/solutions/2805777/longest-repeating-character-replacement/
//* https://leetcode.com/problems/longest-repeating-character-replacement/submissions/896647754/
//* https://www.youtube.com/watch?v=gqXU1UyA8pk

class Solution {
public:
    // O(26*n)->
    /*
    int max_value(map<char,int> mp){
        int maxi = INT_MIN;
        for(auto& m : mp){
            maxi = max(maxi, m.second);
        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        int n = s.length();
        map<char, int> mp;
        int answer = 0;
        int i = 0 , j = 0;
        while(j < n){
            mp[s[j]]++;
            int window_length = j - i + 1;
            int max_freq = max_value(mp);
            while(i<=j && window_length - max_freq > k){
                mp[s[i]]--;
                i++;
                window_length = j - i + 1;
                max_freq = max_value(mp);
            }
            answer = max(answer, window_length);
            j++;
        }
        return answer;
    }
    */

    // O(n)
    int characterReplacement(string s, int k) {
        int n = s.length();
        map<char, int> mp;
        int answer = 0;
        int max_freq = 0;
        int i = 0 , j = 0;
        while(j < n){
            mp[s[j]]++;
            int window_length = j - i + 1;
            max_freq = max(max_freq, mp[s[j]]);
            
            if(i<=j && window_length - max_freq > k){
                mp[s[i]]--;
                i++;
                window_length = j - i + 1;
            }
            answer = max(answer, window_length);
            j++;
        }
        return answer;
    }
};