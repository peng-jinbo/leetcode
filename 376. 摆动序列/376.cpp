class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;
        int result = 1;
        int tag = 0;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] == nums[i-1]) continue;
            else if((tag==0||tag == 1) && nums[i] < nums[i-1])
            {
                result += 1;
                tag = 2;
            }
            else if((tag==0||tag == 2) && nums[i] > nums[i-1])
            {
                result += 1;
                tag = 1;
            }
        }
        return result;
    }
};