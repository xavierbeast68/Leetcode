//* https://leetcode.com/problems/product-of-array-except-self/

class Solution {
public:
    void left_product(vector<int>& left, vector<int> nums, int n){
        left[0] = nums[0];
        for(int i = 1; i < n; ++i){
            left[i] = left[i-1] * nums[i];
        }
    }
    void right_product(vector<int>& right, vector<int> nums, int n){
        right[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; --i){
            right[i] = right[i+1] * nums[i];
        }
    }
    // void debug(vector<int> arr){
    //     for(auto i : arr){
    //         cout << i << "," ;
    //     }
    //     cout << endl;
    // }

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        // creating auxillary arrays
        vector<int> left(n); left_product(left, nums, n);
        vector<int> right(n); right_product(right, nums, n);
        // debug(left);
        // debug(right);

        vector<int> answer(n);
        answer[0] = right[1];
        answer[n-1] = left[n-2];
        for(int i = 1; i < n-1; i++){
            answer[i] = left[i-1] * right[i+1];
        }
        return answer;
    }
};