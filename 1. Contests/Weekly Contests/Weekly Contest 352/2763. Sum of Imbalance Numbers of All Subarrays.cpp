//* https://leetcode.com/problems/sum-of-imbalance-numbers-of-all-subarrays/
//* https://www.youtube.com/watch?v=Ec67Jgw22uE&t=50s
//* https://leetcode.com/problems/sum-of-imbalance-numbers-of-all-subarrays/solutions/3708942/video-explanation-2-approaches-n-n-and-n/

class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        
        // Brute Forcce-> O(n*n*(logn)*n)

        // Approach-1 : O(n*n)
        return approach_1(nums);
        
        // Approach-2 : O(n)
        // return approach_2(nums);
        //* https://www.youtube.com/watch?v=Ec67Jgw22uE&t=50s
    }

    int approach_1(vector<int>& nums){
        int n = nums.size();
        int ansImb = 0;

        for(int i = 0; i < n; i++){
            unordered_set<int> s;
            s.insert(nums[i]);
            int currImb = 0;
            
            for(int j = i + 1; j < n; j++){
                // if count = 0, means nums[j] not present before and may change number of imbalances already present
                // if count = 1, means that nums[j] will not contribute anything to number of good pairs, already present previously
                // find fn has complexity of O(n), count function has avg case complexity = O(1), worst case = O(n)
                // for unordered set
                if(s.count(nums[j]) == 0){
                    // addition of new pair - (breaking of already existing good pair in left) - (breaking of already existing good pair in right)
                    currImb += 1 - (s.count(nums[j]-1) > 0) - (s.count(nums[j] + 1) > 0);
                }

                ansImb += currImb;
                s.insert(nums[j]);
            }
        }

        return ansImb;
    }

    // int approach_2(vector<int>& nums){
        // https://www.youtube.com/watch?v=Ec67Jgw22uE&t=50s
    // }
};