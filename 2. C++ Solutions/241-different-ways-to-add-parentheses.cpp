//* https://leetcode.com/problems/different-ways-to-add-parentheses/
//* https://www.codingninjas.com/codestudio/library/different-ways-to-add-parentheses

class Solution {
public:
    int operation(int x, int y, char op){
        if(op == '+'){
            return x+y;
        }
        if(op == '*'){
            return x*y;
        }
        if(op == '-'){
            return x-y;
        }
        return 0;
    }

    vector<int> diffWaysToCompute(string expression) {
        // vector<int> ans;

        // int n = expression.length();
        // for(int i = 0; i < n; i++){
        //     char ch = expression[i];

        //     if(isdigit(ch)){
        //         continue;
        //     }

        //     vector<int> pre = diffWaysToCompute(expression.substr(0,i));
        //     vector<int> suff = diffWaysToCompute(expression.substr(i+1));
        //     for(auto &p : pre){
        //         for(auto &s : suff){
        //             int val = operation(p, s, ch);
        //             ans.push_back(val);
        //         }
        //     }
        // }
        // if(ans.empty()){
        //     ans.push_back(stoi(expression));
        // }
        // return ans;

        vector<int> results;
        bool noOperator = true;
        for(int i = 0; i< expression.length(); i++){
            if(!(isdigit(expression[i]))){
                noOperator = 0;
                vector<int> pre = diffWaysToCompute(expression.substr(0,i));
                vector<int> suff = diffWaysToCompute(expression.substr(i+1));
                for(auto &p : pre){
                    for(auto &s : suff){
                        int val = operation(p, s, expression[i]);
                        results.push_back(val);
                    }
                }
            }
        }
        if(noOperator){
            results.push_back(stoi(expression));
        }
        return results;
    }
};