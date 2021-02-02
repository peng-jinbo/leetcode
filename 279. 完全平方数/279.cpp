class Solution {
public:
    int numSquares(int n) {
        int Max_num = pow(2,31)-1;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            if(int(sqrt(i)) * int(sqrt(i)) == i)
            {
                dp[i] = 1;
                continue;
            }
            else
            {
                int k = 1;
                int min_num = Max_num;
                while(k*k < i)
                {
                    if(dp[k*k] + dp[i-k*k] < min_num) min_num = dp[k*k] + dp[i-k*k];
                    k++;
                }
                dp[i] = min_num;
            }
        }
        return dp[n];
    }
};