//* https://leetcode.com/problems/container-with-most-water/description/ */

class Solution {
    public int maxArea(int[] height) {
        int maxWater = Integer.MIN_VALUE;
        int n = height.length;

        int lp = 0, rp = n - 1;
        while(lp < rp){
            int ht = Math.min(height[lp],height[rp]);
            int wd = rp - lp;
            int water = ht * wd;
            maxWater = Math.max(maxWater, water);

            if(height[lp] < height[rp]){
                ++lp;
            } else {
                // rp <= lp
                --rp;
            }
        }
        return maxWater;
    }
}