class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 0) return 0;
        vector<int> dp(n,-pow(2,31));
        for(int i = 0; i < n; i++)
        {
            int temp = dp[0];
            for(int j = 0; j <= i; j++)
            {
                if(i == 0)
                {
                    dp[j] = triangle[i][j];
                    continue;
                }
                if(j == 0)
                    dp[j] = triangle[i][j] + dp[j];
                else if(j == i) dp[j] = triangle[i][j] + temp;
                else{
                    int temp1 = dp[j];
                    dp[j] = min(temp,dp[j]) + triangle[i][j];
                    temp = temp1;
                }
            }
        }
        int result = dp[0];
        for(int i = 1; i < n; i++)
        {
            result = min(result,dp[i]);
        }
        return result;

    }
};