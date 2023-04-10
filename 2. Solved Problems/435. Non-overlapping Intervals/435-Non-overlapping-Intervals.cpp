//* similar to Activity Selection Problem
//* https://leetcode.com/problems/non-overlapping-intervals/description/

class comp{
    public:
    bool operator()(vector<int>& a, vector<int>& b){
        if(a[1] == b[1]){
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }
};
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp());

        int n = intervals.size();
        int cnt = 1; // count of non_overlapping intervals
        int curr_end = intervals[0][1]; 
        for(int i = 1; i < n; ++i){
            if(curr_end <= intervals[i][0]){
                cnt++;
                curr_end = intervals[i][1];
            }
        }

        return n-cnt; // Overlapping intervals
    }
};