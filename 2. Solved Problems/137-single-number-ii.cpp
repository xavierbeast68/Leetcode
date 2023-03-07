//* https://leetcode.com/problems/single-number-ii/description/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> mp;
        for(int i : nums) ++mp[i];

        int answer;
        for(auto i : mp){
            if(i.second == 1){
                answer = i.first;
                break;
            }
        }
        return answer;
    }
};