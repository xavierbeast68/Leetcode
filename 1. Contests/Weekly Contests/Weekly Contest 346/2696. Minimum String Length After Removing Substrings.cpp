//* https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/

class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        
        for(char ch : s){
            if(!st.empty()){
                if(ch == 'B' && st.top() == 'A'){
                    st.pop();
                }
                else if(ch == 'D' && st.top() == 'C'){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
            else{
                st.push(ch);
            }
        }
        
        int ans = 0;
        while(!st.empty()){
            ans++;
            st.pop();
        }
        
        return ans;
    }
};