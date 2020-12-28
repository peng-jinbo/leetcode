class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin = 0;
        int end = nums.size()-1;
        while(begin < end)
        {
            int mid = (begin + end) / 2;
            if(nums[mid] >= nums[0])
            {
                begin = mid + 1;
            }
            else
            {
                if(nums[mid] < nums[mid-1]) return nums[mid];
                else end = mid-1;
            }
        }
        return min(nums[begin], min(nums[0],nums[end]));
    }
};