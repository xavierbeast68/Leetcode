//* similar to Activity Selection Problem
//* https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

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
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp());

        int n = points.size();
        int cnt = 1; // count of non_overlapping points
        int curr_end = points[0][1]; 
        for(int i = 1; i < n; ++i){
            if(curr_end < points[i][0]){
                cnt++;
                curr_end = points[i][1];
            }
        }

        return cnt;
    }
};