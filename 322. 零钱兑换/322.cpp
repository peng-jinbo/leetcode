class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int INT_max = pow(2,31)-1;
        int m = coins.size();
        vector<int> dp(amount+1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            int temp = INT_max;
            for(int j = 0; j < m; j++)
            {
                if(i - coins[j] >= 0 && dp[i - coins[j]] != -1)
                {
                    temp = min(temp, dp[i - coins[j]]);
                }
            }
            dp[i] = (temp == INT_max)?-1:temp+1;
        }
        return dp[amount];
    }
};