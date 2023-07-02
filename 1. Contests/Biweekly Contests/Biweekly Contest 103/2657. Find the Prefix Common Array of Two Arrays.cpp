//* https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int,int> mp1, mp2;
        for(int i = 1; i <= 50; ++i){
            mp1[i] = 0;
            mp2[i] = 0;
        }
        
        int cnt = 0;
        vector<int> ans;
        
        int n = A.size();
        
        for(int i = 0; i < n; ++i){
            if(mp1[B[i]] == 1){
                cnt++;
            }
            mp2[B[i]] = 1;
            
            if(mp2[A[i]] == 1){
                cnt++;
            }
            mp1[A[i]] = 1;
            
            ans.push_back(cnt);
        }
        
        return ans;
    }
};