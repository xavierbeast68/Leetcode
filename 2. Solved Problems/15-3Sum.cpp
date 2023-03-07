//* https://leetcode.com/problems/3sum/description/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        set<vector<int>> st;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0;
        while(i <= n-3){
            if(i>0 && nums[i]==nums[i-1]){
                i++;
            }

            int j = i+1;
            int k = n-1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum > 0){
                    k--;

                } else if(sum < 0){
                    j++;
                }
                else{ // (sum == 0)
                    st.insert({nums[i],nums[j],nums[k]});
                    j++;
                    while(nums[j] == nums[j-1] && j < k){
                        j++;
                    }
                }
            }
            i++;
        }
        for(auto i : st){
            answer.push_back(i);
        }
        return answer;
    }
};