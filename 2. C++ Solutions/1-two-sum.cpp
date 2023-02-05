//* https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> answer;
        unordered_map<int,int> ump;
        for(int i = 0; i < n; i++){
            if(ump.find(target - nums[i]) != ump.end()){
                answer.push_back(i);
                answer.push_back(ump[target-nums[i]]);
            }
            ump[nums[i]] = i;
        }
        return answer;
    }
};