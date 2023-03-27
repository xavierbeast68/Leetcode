//* https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/description/
//* https://www.youtube.com/watch?v=TUXKRTPWS6U&ab_channel=PrakharAgrawal

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long> ans;
        
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int m = queries.size();
        vector<long long> pre(n);
        pre[0] = nums[0];
        for(int i = 1; i<n; ++i){
            pre[i] = pre[i-1] + nums[i];
        }

        for(int i = 0; i<m; ++i){
            long long target = queries[i];
            long long addNum, subNum;
            long long smallInd = upper_bound(begin(nums), end(nums), target) - nums.begin();
            if(smallInd == 0){
                addNum = 0;
                subNum = pre[n-1] - (n*target);
            }
            else if(smallInd == n){
                addNum = (n*target) - pre[n-1];
                subNum = 0;
            }
            else{
                addNum = ((smallInd)*target) - pre[smallInd-1];
                subNum = (pre[n-1] - pre[smallInd-1]) - ((n - (smallInd))*target);
            }

            ans.push_back(addNum+subNum);
        }


        return ans;
    }
};