//* https://leetcode.com/contest/weekly-contest-334/problems/left-and-right-sum-differences/
//* https://leetcode.com/problems/left-and-right-sum-differences/


class Solution {
public:
    void prefix(vector<int>& pre, vector<int>& nums, int n){
        pre[0] = nums[0];
        for(int i = 1 ; i < n ; ++i){
            pre[i] = pre[i-1] + nums[i];
        }
    }
    void suffix(vector<int>& suff, vector<int>& nums, int n){
        suff[n-1] = nums[n-1];
        for(int i = n-2 ; i >= 0 ; --i){
            suff[i] = suff[i+1] + nums[i];
        }
    }
    vector<int> leftRigthDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n,0);
        if(n==1){
            return answer;
        }
        
        vector<int> pre(n,0);
        vector<int> suff(n,0);
        prefix(pre, nums, n);
        suffix(suff, nums, n);
        
        for(int i = 0 ; i < n ; ++i){
            if(i==0){
                answer[i] = suff[i+1];
            }
            else if(i == n-1){
                answer[i] = pre[i-1];
            }
            else{
                answer[i] = abs(pre[i-1] - suff[i+1]);
            }
        }
        return answer;
    }
};