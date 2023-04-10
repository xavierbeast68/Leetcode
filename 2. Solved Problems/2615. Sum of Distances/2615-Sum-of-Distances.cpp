//* https://leetcode.com/problems/sum-of-distances/description/
//* Optimised-> https://www.youtube.com/watch?v=IgxZ-jU8sr8&ab_channel=PrakharAgrawal

#define vi                                          vector<int>
#define FOR(i,a,b)                                  for(int i = a; i < b; ++i)
#define pb                                          push_back

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        // TLE
        // unordered_map<int, vector<int>> mp;
        // for(int i = 0; i < n; ++i){
        //     mp[nums[i]].push_back(i);
        // }
        // vector<long long> sumAns;
        // for(int i = 0; i < n; ++i){
        //     long long sum = 0;
        //     for(auto ind : mp[nums[i]]){
        //         sum += abs(i-ind);
        //     }
        //     sumAns.push_back(sum);
        // }
        // return sumAns;



        vector<long long> ans(n);
        unordered_map<int, vector<int>> mp;

        FOR(i,0,n){
            mp[nums[i]].pb(i);
        }

        for(auto it : mp){
            vi arr = it.second;
            int nn = arr.size();
            if(nn == 1){
                ans[arr[0]] = 0;
                continue;
            }

            long long leftSum = 0, rightSum = 0, res = 0;
            for(auto s : arr){
                rightSum += s;
            }

            for(int i = 0; i < nn; ++i){
                res += ((long long)i*(long long)arr[i]) - leftSum;
                res += rightSum - ((long long)(nn-i)*(long long)arr[i]);

                leftSum += arr[i];
                rightSum -= arr[i];
                
                ans[arr[i]] = res;
                res = 0;
            }
        }

        return ans;
    }
};