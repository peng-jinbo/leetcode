class Solution {
public:
    int numDistinct(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        vector<vector<long>> dp(len1+1,vector<long>(len2+1,0));
        for(int i = 0; i <= len1; i++) dp[i][0] = 1;
        for(int i = 0; i < len1; i++)
        {
            for(int j = 0; j <= i && j<len2; j++)
            {
                if(s[i] == t[j])
                {
                    dp[i+1][j+1] = dp[i][j] + dp[i][j+1];
                }
                else
                {
                    dp[i+1][j+1] = dp[i][j+1];
                }
            }
        }
        return (int) dp[len1][len2];
    }
};