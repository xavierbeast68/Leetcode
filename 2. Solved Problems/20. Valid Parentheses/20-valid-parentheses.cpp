//* https://leetcode.com/problems/valid-parentheses/description/
//* https://leetcode.com/problems/valid-parentheses/submissions/896420852/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        // map<char,char> mp;
        // mp[')'] = '(';
        // mp[']'] = '[';
        // mp['}'] = '{';
        for(auto& ch : s){
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }
            else if(st.size() > 0){
                char c = st.top();

                // if(mp[ch] == st.top())
                if((c=='(' && ch == ')') || (c=='[' && ch == ']') || (c=='{' && ch == '}'))
                {
                    st.pop();
                } else{
                    return false;
                }
            }
            else{
                return false;
            }
        }

        if(st.size() > 0){
            return false;
        } else{
            return true;
        }
    }
};