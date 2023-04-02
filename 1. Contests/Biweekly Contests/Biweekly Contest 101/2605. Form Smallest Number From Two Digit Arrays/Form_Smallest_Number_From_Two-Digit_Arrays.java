//* https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/description/
//* https://www.youtube.com/watch?v=M0RjiC85BZU
//* https://www.youtube.com/watch?v=ZlVNO8BFBCY

import java.util.*;

class Form_Smallest_Number_From_Two_Digit_Arrays{
    public static void main(String[] args) {
    }
}

class Solution {
    public int minNumber(int[] nums1, int[] nums2) {
        // O(n)
        Map<Integer,Integer> mp = new HashMap<>();
        int min_el = 10, min1 = 10, min2 = 10;

        for(int i : nums1){
            mp.put(i, 1);
            min1 = Math.min(min1, i);
        }

        for(int i : nums2){
            if(mp.containsKey(i)){
                min_el = Math.min(min_el, i);
            }

            min2 = Math.min(min2, i);
        }

        if(min_el != 10){
            return min_el;
        }

        return (Math.min(min1, min2) * 10 + Math.max(min1, min2));
    }
}