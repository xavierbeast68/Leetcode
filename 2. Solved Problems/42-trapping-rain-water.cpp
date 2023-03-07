//* https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    vector<int> leftmax_boundary(vector<int> height, int n){
        vector<int> left(n);
        left[0] = 0;

        for(int i = 1; i < n; ++i){
            left[i] = max(left[i-1], height[i-1]);
        }

        return left;
    }
    vector<int> rightmax_boundary(vector<int> height, int n){
        vector<int> right(n);
        right[n-1] = 0;

        for(int i = n-2; i >= 0; --i){
            right[i] = max(right[i+1], height[i+1]);
        }

        return right;
    }

    // void debug(vector<int> arr){
    //     for(auto i : arr){
    //         cout << i << "," ;
    //     }
    //     cout << endl;
    // }

    int trap(vector<int>& height) {
        int n = height.size();

        // creating auxillary arrays
        vector<int> left_boundary = leftmax_boundary(height, n);
        vector<int> right_boundary = rightmax_boundary(height, n);
        // debug(left_boundary);
        // debug(right_boundary);

        int trapped_water = 0;
        for(int i = 1; i < n-1; ++i){
            int water_level = min(left_boundary[i], right_boundary[i]);
            int water_quantity = water_level - height[i];

            if(water_quantity > 0){
                trapped_water += water_quantity;
            }
        }

        return trapped_water;
    }
};