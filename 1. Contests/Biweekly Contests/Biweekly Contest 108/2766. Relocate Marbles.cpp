//* https://leetcode.com/problems/relocate-marbles/

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {

        unordered_map<int,int> mp;
        int sz = nums.size();
        for(int i = 0; i < sz; i++){
            // cout << nums[i] << endl;
            mp[nums[i]]++;
        }
        // dbg(mp);
        
        int n = moveFrom.size();
        for(int i = 0; i < n; i++){
            if(mp.find(moveFrom[i]) != mp.end()){
                mp.erase(moveFrom[i]);
                mp[moveTo[i]]++;
            }
        }
        
        // dbg(mp);
        
        vector<int> ans;
        for(auto it : mp){
            ans.push_back(it.first);
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
    
    void dbg(unordered_map<int,int> mp){
        for(auto it : mp){
            cout << it.first << " ";
        }
        cout << endl;
    }
};