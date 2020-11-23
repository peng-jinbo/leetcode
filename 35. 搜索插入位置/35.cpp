class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;
        int left = 0;
        int right = nums.size() - 1;
        while(left<right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return nums[left] >= target?left:left+1;
    }
};