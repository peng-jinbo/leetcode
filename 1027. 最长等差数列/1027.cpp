class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int maxs = 2, n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, 2));
        vector<int> mp(20001, -1);
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                int target = 2 * A[i] - A[j];
                if(target < 0) continue;
                if(mp[target] != -1) dp[i][j] = dp[mp[target]][i] + 1;
                maxs = max(maxs, dp[i][j]);
            }
            mp[A[i]] = i;
        }
        return maxs;
    }
};