class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxF = nums[0];
        int minF = nums[0];
        int result = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            int temp = maxF;
            maxF = max(maxF*nums[i],max(minF*nums[i],nums[i]));
            minF = min(minF*nums[i],min(temp*nums[i],nums[i]));
            result = max(result, maxF);
        }
        return result;
    }
};