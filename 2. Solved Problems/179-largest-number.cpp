//* https://leetcode.com/problems/largest-number/description/

class Solution {
public:
    static bool comp(int x, int y)
    {
        string xy = to_string(x) + to_string(y);
        string yx = to_string(y) + to_string(x);

        // return xy.compare(yx) > 0;
        return xy > yx;
    }

    string largestNumber(vector<int> &nums)
    {
        // edge case
        int count_zero = count(nums.begin(), nums.end(), 0);
        if(count_zero == nums.size()){
            return "0";
        }


        //! comp should be a static function
        sort(nums.begin(), nums.end(), comp);
        string ans = "";
        for (auto i : nums)
        {
            ans += to_string(i);
        }

        return ans;
    }
};