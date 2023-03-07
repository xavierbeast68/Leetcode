//* https://leetcode.com/problems/merge-intervals/

class Solution
{
public:
    int solve(vector<vector<int>> &intervals, vector<vector<int>> &ans, int left, int right, int i, int n)
    {
        // base conditions->
        if (i == n - 1)
        {
            ans.push_back({left, right});
            return n; // means (n-1)th element of intervals is also included
        }
        // b1 < a2, no overlap
        if (right < intervals[i + 1][0])
        {
            ans.push_back({left, right});
            return i + 1;
        }

        // b1 == a2
        if (right == intervals[i + 1][0])
        {
            // no change in left
            right = intervals[i + 1][1];
            return solve(intervals, ans, left, right, i + 1, n);
        }
        // b1 > a2, a1 <= a2 already known
        else
        {
            // b1 <= b2
            if (right <= intervals[i + 1][1])
            {
                // left remain same
                right = intervals[i + 1][1];
                return solve(intervals, ans, left, right, i + 1, n);
            }
            // b1 > b2
            else
            {
                // left remain same
                // right remain same
                return solve(intervals, ans, left, right, i + 1, n);
            }
        }
    }

    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        if (n == 1)
        {
            return intervals;
        }

        vector<vector<int>> answer;
        sort(begin(intervals), end(intervals));
        // a1 <= a2 always

        int i = 0;
        while (i < n - 1)
        {
            int left = intervals[i][0], right = intervals[i][1];
            i = solve(intervals, answer, left, right, i, n);
        }

        if (i == n - 1) // means (n-1)th not included
        {
            answer.push_back(intervals[n - 1]);
        }

        return answer;
    }
};