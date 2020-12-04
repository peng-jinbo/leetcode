class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == '0') dp[i][j] = 0;
                else
                {
                    if(j == 0) dp[i][j] = 1;
                    else dp[i][j] = dp[i][j-1] + 1;
                }
            }
        }
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(dp[i][j] == 0) continue;
                else{
                    int min_num = dp[i][j];
                    for(int k = i; k >= 0; k--)
                    {
                        if(dp[k][j] == 0) break;
                        else{
                            min_num = min(min_num,dp[k][j]);
                            int temp = (i-k+1)*min_num;
                            result = max(result,temp);
                        }
                    }
                }
            }
        }
        return result;
    }
};