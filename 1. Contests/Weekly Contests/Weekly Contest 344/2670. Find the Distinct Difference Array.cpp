//* https://leetcode.com/problems/find-the-distinct-difference-array/description/

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n, 0), pref(n,0), suff(n,0);
        
        unordered_map<int, int> mp;
        // prefix->
        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
            pref[i] = mp.size();
        }
        mp.clear();
        // suffix->
        for(int i = n-1; i >= 0; i--){
            suff[i] = mp.size();
            mp[nums[i]]++;
        }
        
        for(int i = 0; i < n; i++){
            diff[i] = pref[i] - suff[i];
        }
        
        return diff;
    }
};