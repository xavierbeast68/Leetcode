//* https://leetcode.com/problems/container-with-most-water/description/

class Solution {
public:
    
    int maxArea(vector<int>& height) {
        int maxWater = INT_MIN;
        int n = height.size();

        // // Brute Force -> O(n^2), gives TLE
        // for(int i = 0 ; i < n ; ++i){
        //     for(int j = i + 1 ; j < n ; ++j){
        //         int ht = min(height[i], height[j]);
        //         int width = j - i;
        //         int water = ht * width;
        //          maxWater = max(maxWater, water);
        //     }
        // }

        // Two-pointers Approach-> O(n)
        int lp = 0, rp= n - 1;
        while(lp < rp){
            int ht = min(height[lp],height[rp]);
            int wd = rp - lp;
            int water = ht * wd;
            maxWater = max(maxWater, water);

            if(height[lp] < height[rp]){
                ++lp;
            } else {
                // rp <= lp
                --rp;
            }
        }
        return maxWater;
    }
};