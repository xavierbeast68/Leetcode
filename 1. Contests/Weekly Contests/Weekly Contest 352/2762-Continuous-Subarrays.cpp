//* https://leetcode.com/problems/continuous-subarrays/
//* https://www.youtube.com/watch?v=tHPMTQDArls&ab_channel=codingMohan
//* https://leetcode.com/problems/continuous-subarrays/solutions/3707067/video-explanation-3-approaches-2-pointers-binary-search-next-prev-smaller-element/

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        map<int,int> mp;
        
        int n = nums.size();
        long long ans = 0;
        int i = 0, j = 0, maxi = INT_MIN, mini = INT_MAX;
        while(j < n){
            mp[nums[j]]++;
            
            mini = (*mp.begin()).first;
            maxi = (*mp.rbegin()).first;
            
            while(i < j && maxi-mini > 2){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                    mini = (*mp.begin()).first;
                    maxi = (*mp.rbegin()).first;
                }
                
                ans = ans + (j-i); // (j-i) is combinations of subarray possible in range i to (j-1)
                i++;
            }
            
            j++;
        }
        cout << i << " " << j << endl;
        
        // remaining subarrays
        while(i < j){    
            ans = ans + (j-i);
            i++;
        }
        
        return ans;
    }
};