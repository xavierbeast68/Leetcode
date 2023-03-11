//* https://leetcode.com/problems/valid-parentheses/description/

class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();

        for(int i = 0; i < s.length(); ++i){
            char ch = s.charAt(i);

            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }

            else{
                if(st.isEmpty()){
                    return false;
                }

                else{
                    char c = st.peek();
                    if(ch == ')' && c == '(' || ch == '}' && c == '{' || ch == ']' && c == '['){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
            }
        }

        if(!st.isEmpty()){
            return false;
        }
        else{
            return true;
        }
    }
}