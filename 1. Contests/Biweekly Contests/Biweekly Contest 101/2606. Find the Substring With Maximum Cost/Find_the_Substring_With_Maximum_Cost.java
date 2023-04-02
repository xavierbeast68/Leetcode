import java.util.*;

public class Find_the_Substring_With_Maximum_Cost {
    public static void main(String[] args) {
        
    }
}

//* https://leetcode.com/problems/find-the-substring-with-maximum-cost/
//* https://www.youtube.com/watch?v=LA3CLwulZzY
//* https://www.youtube.com/watch?v=EwSIfXGq2B4

class Solution {
    public int maximumCostSubstring(String s, String chars, int[] vals) {
        int num[] = new int[s.length()];
        for(int i=0; i< s.length(); ++i){
            char ch = s.charAt(i);
            
            if(chars.indexOf(ch) != -1){
                num[i] = vals[chars.indexOf(ch)];
            }
            else{
                num[i] = ch - 'a' + 1;
            }
        }
        
        // using Kadane's Algorithm
        int n = num.length;
        int ms = Integer.MIN_VALUE;
        int cs = 0;
        for(int i = 0; i < n; i++)
        {
            cs = cs + num[i];
            if(cs < 0)
            {
                cs = 0;
            }
            ms = Math.max(ms,cs);
        }
        
        return ms;
    }
}