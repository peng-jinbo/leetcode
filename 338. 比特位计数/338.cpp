class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1);
        dp[0] = 0;
        if(num == 0) return dp;
        dp[1] = 1;
        int count = 2;
        for(int i = 2; i <= num; i++)
        {
            if(i == count)
            {
                dp[i] = 1;
                count *= 2;
            }
            else
            {
                dp[i] = dp[i - (count/2)] + 1;
            }
        }
        return dp;
    }
};