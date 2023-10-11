//* https://leetcode.com/problems/account-balance-after-rounded-purchase/

class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        if(purchaseAmount%10 == 0){
            return 100 - purchaseAmount;
        }
        
        int rem = purchaseAmount%10;
        
        int left = rem;
        int right = 10 - rem;
        
        if(left >= right){
            return 100 - (purchaseAmount + right);
        }
        else{
            return 100 - (purchaseAmount - left);
        }
    }
};