//* https://leetcode.com/problems/minimum-seconds-to-equalize-a-circular-array/description/

class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        
        unordered_map<int, vector<int>> pos;
        
        int n = nums.size();
        for(int i = 0; i < n; i++){
            pos[nums[i]].push_back(i);
        }
        if(pos.size() == 1){
            return 0;
        }
        
        int minDist = INT_MAX;
        for(auto num : pos){
            // cout << "num : " << num.first << endl;

            vector<int> position = num.second;
            
            int posLen = position.size();
            
            int firstPos = position[0], lastPos = position[posLen-1];
            
            int maxDist = (int) ceil ((double) (firstPos + n-1 - lastPos) / (double)2); // circular distance of two farthest sources
            
            // cout << firstPos << "+" << n-1 << "-" << lastPos << endl;
            // cout << maxDist << endl;
            
            for(int i = 1; i < posLen; i++){
                int dist = (int) ceil ((double) (position[i]-position[i-1]-1) / (double)2);
                
                // cout << "dist : " << dist << endl;
                // cout << pos[1] << "-" << pos[0] << "-" << 1 << endl;
                
                maxDist = max(maxDist, dist);
            }
            
            minDist = min(minDist, maxDist);
            // cout << "minDist : " << minDist << endl;
        }
        
        return minDist;
    }
};