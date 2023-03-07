//* https://leetcode.com/problems/find-the-duplicate-number/description/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for(int i : nums) ++mp[i];

        int answer;
        for(auto i : mp){
            if(i.second > 1){
                answer = i.first;
                break;
            }
        }
        return answer;
    }
};