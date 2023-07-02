//* https://leetcode.com/problems/minimum-additions-to-make-valid-string/description/

// Soln using stack->
class Solution {
public:
    int addMinimum(string word) {
        stack<char> st;
        for(int i = 0; i < word.length(); i++)       
            st.push(word[i]);


        int count = 0;

        while(!st.empty())
        {
            if(!st.empty() && st.top() == 'c')            
                st.pop();            
            else count++;

            if(!st.empty() && st.top() == 'b')            
                st.pop();            
            else count++;

            if(!st.empty() && st.top() == 'a')
                st.pop();            
            else count++;

        }

        return count;
    }
};

// Brute Force->
// class Solution {
// public:
//     int addMinimum(string word) {
//         if(word.length() == 1){
//             return 2;
//         }
        
//         int inserts = 0;
//         if(word[0] == 'b'){ // starting letter is 'b'-> ab
//             inserts++;
//         }
//         if(word[0] == 'c'){ // starting letter is 'c'-> abc
//             inserts += 2;
//         }
//         for(int i = 1; i < word.length(); ++i){
            
//             int diff = word[i] - word[i-1];
            
//             if(i == (word.length()-1)){
//                 // last letter
//                 if(word[i] == 'b'){
//                     inserts++;
//                 }
//                 else if(word[i] == 'a'){
//                     inserts += 2;
//                 }
//             }
            
//             if(diff == 0){
//                 // aa-> abca, bb-> bcab, cc-> cabc
//                 inserts += 2;
//             }
//             else if(diff == 1){
//                 // ab, bc
//                 continue;
//             }
//             else if(diff == 2){
//                 // ac -> abc
//                 inserts++;
//             }
//             else if(diff == -1){
//                 // ba -> bca
//                 inserts++;
//             }
//             else if(diff == -2){
//                 // ca
//                 continue;
//             }
//         }
        
//         return inserts;
//     }
// };