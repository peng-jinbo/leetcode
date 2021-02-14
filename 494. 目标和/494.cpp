class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        dfs(nums,0,S,0);
        return result;
    }
    void dfs(vector<int>& nums, int pos, int S, int temp)
    {
        if(pos == nums.size()) 
        {
            if(temp == S) 
                result++;
            return;
        }
        dfs(nums, pos+1, S, temp+nums[pos]);
        dfs(nums, pos+1, S, temp-nums[pos]);

    }
private:
    int result = 0;
};