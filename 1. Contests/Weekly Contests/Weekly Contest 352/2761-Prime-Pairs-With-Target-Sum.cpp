//* https://leetcode.com/problems/prime-pairs-with-target-sum/

class Solution {
public:
    bool isPrime(int n){
        if (n == 2 || n == 3){
            return true;
        } 
        if(n <= 1 || n % 2 == 0 || n % 3 == 0)
        {
            return false;
        } 
        for(int i = 5; i * i <= n; i += 6){
            if (n % i == 0 || n % (i + 2) == 0){
                return false;
            }
        } 
        
        return true;
    }
    
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> ans;
        for(int i = 2; i <= n/2; i++){
            if(isPrime(i) && isPrime(n-i)){
                ans.push_back({i, n-i});
            }
        }
        
        return ans;
    }
};