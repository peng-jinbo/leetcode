class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        vector<vector<int>> dp(destination[0]+1,vector<int>(destination[1]+1,0));
        string result = "";
        //更新dp，记录每种情况有多少种组合
        for(int i = 0; i < destination[0]+1; i++)
        {
            for(int j = 0; j < destination[1]+1; j++)
            {
                if(i ==0 || j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        int h = destination[1];
        int v = destination[0];
        // 前缀和求解
        while(h>0||v>0)
        {
            if(h > 0 && v > 0)
            {
                if(k <= dp[v][h-1])
                {
                    result += 'H';
                    h--;
                }
                else
                {
                    result += 'V';
                    k -= dp[v][h-1];
                    v--;
                }
            }
            else if(h > 0)
            {
                result += 'H';
                h--;
            }
            else
            {
                result += 'V';
                v--;
            }
        }
        return result;
    }
};