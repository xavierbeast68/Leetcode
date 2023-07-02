//* https://leetcode.com/problems/find-the-punishment-number-of-an-integer/description/

class Solution {
public:
    bool sumPart(int num, int dig, int target){
        if(num == target){
            return true;
        }
        
        int div = 10;
        for(int j = 1; j < dig; j++){
            int temp = num%div;
            if(div > num || temp > target){
                break;
            }
            if(sumPart(num/div, dig-j, target - temp)){
                return true;
            }
            div *= 10;
        }
        
        return false;
    }
    int punishmentNumber(int n) {
        int sum = 1;
        
        for(int i = 2; i <= n; i++){
            int dig = floor(log10(i*i)+1);
            if(sumPart(i*i, dig, i)){
                sum += i*i;
                cout << i << endl;
            }
        }
        return sum;
    }
};