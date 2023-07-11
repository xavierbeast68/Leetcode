//* https://leetcode.com/problems/partition-string-into-minimum-beautiful-substrings/
//* https://www.youtube.com/watch?v=Jik3zfAhA8w

class Solution {
public:
    int mini;
    bool check(string str){
        if(str[0] == '0'){
            return false;
        }
        
        int dec_num = 0;
        int power = 0 ;
        int n = str.length();
        for(int i = n-1; i >= 0; i--){
            if(str[i] == '1'){
                dec_num += (1<<power) ;
            }
            power++ ;
        }
     
        while(dec_num > 0 && dec_num%5 == 0){
            dec_num /= 5;
        }
        return (dec_num == 1);
    }
    void partition(string s, vector<string>& temp){
        if(s.length() == 0){
            int sz = (int)temp.size();
            mini = min(mini, sz);
            return;
        }
        for(int i = 1; i <= s.length(); ++i){
            string part1 = s.substr(0, i);
            string part2 = s.substr(i);
            
            if(check(part1)){
                temp.push_back(part1);
                partition(part2, temp);
                temp.pop_back();
            }
        }
    }
    int minimumBeautifulSubstrings(string s) {
        mini = INT_MAX;
        vector<string> temp;
        partition(s, temp);
        return mini == INT_MAX? -1 : mini;
    }
};