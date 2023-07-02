//* https://leetcode.com/problems/collecting-chocolates/
//* https://www.youtube.com/watch?v=rjfWqr-eFLI
//* https://leetcode.com/problems/collecting-chocolates/solutions/3624149/video-explanation-building-solution-with-intuition/
//* https://www.youtube.com/watch?v=6B6fIAa7dws

class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int n = nums.size();
        
        // stores an index of nums array, cost of ith type of chocolate at given operation
        vector<int> order(n);
        // initialize with initial positions
        for(int i = 0; i < n; i++) order[i] = i;

        long long result = 1e18;
        long long operation_cost = 0; // opeartion not yet performed

        // stores min cost of each chocolate;
        vector<int> min_cost = nums;

        // at max n-1 operations are needed to determine the answer
        for(int op = 0; op < n; op++){

            long long val = 0; // storing
            // calculate current minimum cost of all chocolates at opth operation
            for(int i = 0; i < n; i++) val += min_cost[i];

            result = min(result, val + operation_cost);

            // perform operation
            order = shiftOrder(order);
            operation_cost += x;

            //* update min_cost of all chocolates if found lesser cost after performing shift of indices
            for(int i = 0; i < n; i++){

                int curr_cost = nums[order[i]];
                min_cost[i] = min(min_cost[i], curr_cost);
            }
        }

        return result;
    }

    vector<int> shiftOrder(vector<int>& order){
        
        int n = order.size();
        vector<int> newOrder(n);

        for(int i = 0; i < n-1; i++){
            newOrder[i] = order[i+1];
        }
        newOrder[n-1] = order[0];

        return newOrder;
    }
};