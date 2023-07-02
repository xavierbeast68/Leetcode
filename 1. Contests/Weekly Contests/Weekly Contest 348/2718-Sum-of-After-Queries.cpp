//* https://leetcode.com/problems/sum-of-matrix-after-queries/

class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        unordered_set<int> seenRows, seenCols;

        long long sum = 0;
        int q = queries.size();
        for(int i = q-1; i >= 0; --i){
            int type = queries[i][0];
            int index = queries[i][1];
            int val = queries[i][2];

            if(type == 0){
                if(seenRows.find(index) != seenRows.end()){
                    continue;
                }

                sum += val * (n- seenCols.size());
                seenRows.insert(index);
            }
            else{
                if(seenCols.find(index) != seenCols.end()){
                    continue;
                }

                sum += val * (n- seenRows.size());
                seenCols.insert(index);
            }
        }

        return sum;
    }
};