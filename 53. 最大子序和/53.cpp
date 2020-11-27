class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = -pow(2,31);
        int presum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(presum+nums[i] > nums[i]) presum = presum+nums[i];
            else presum = nums[i];
            result = max(result,presum);
        }
        return result;
    }
};