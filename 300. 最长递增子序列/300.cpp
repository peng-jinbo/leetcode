class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> dp(n);
        dp[0] = 1;
        int result = 1;
        for(int i = 1; i < n; i++)
        {
            int max_num = 0;
            for(int j = 0; j < i; j++)
                if(nums[j] < nums[i]) max_num = max(max_num, dp[j]);
            dp[i] = max_num + 1;
            result = max(result,dp[i]);
        }
        return result;
    }
};