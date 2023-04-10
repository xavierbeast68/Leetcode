//* https://leetcode.com/problems/prime-in-diagonal/submissions/
//* https://www.youtube.com/watch?v=eGESnUq2A7I&ab_channel=PrakharAgrawal

class Solution
{
public:
    bool isPrime(int n)
    {
        if (n == 2 || n == 3)
        {
            return true;
        }
        if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        {
            return false;
        }
        for (int i = 5; i * i <= n; i += 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
            {
                return false;
            }
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>> &nums)
    {
        int maxi = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (isPrime(nums[i][i]))
            {
                maxi = max(maxi, nums[i][i]);
            }
            if (isPrime(nums[i][n - i - 1]))
            {
                maxi = max(maxi, nums[i][n - i - 1]);
            }
        }

        return maxi;
    }
};