//* https://leetcode.com/problems/determine-the-winner-of-a-bowling-game/description/

class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int sum1 = 0, sum2 = 0;
        
        int n = player1.size();
        for(int i = 0; i < n; ++i){
            
            if(i == 0){
                sum1 += player1[i];
                sum2 += player2[i];
            }
            else if(i==1){
                sum1 += ((player1[i-1] == 10) ? 2*player1[i] : player1[i]);
                sum2 += ((player2[i-1] == 10) ? 2*player2[i] : player2[i]);
            }
            else{
                sum1 += ((player1[i-1] == 10 || player1[i-2] == 10) ? 2*player1[i] : player1[i]);
                sum2 += ((player2[i-1] == 10 || player2[i-2] == 10) ? 2*player2[i] : player2[i]);
            }
            
        }
        
        return (sum1 == sum2 ? 0 : (sum1 > sum2 ? 1 : 2));
    }
};