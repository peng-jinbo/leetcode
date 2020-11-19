class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = 0;
        if(nums.size() <= 1) return;
        while(left < nums.size())
        {
            if(nums[left] == 0)
            {
                while(right < nums.size() && nums[right] == 0)
                {
                    right++;
                }
                if(right < nums.size())
                    swap(nums[left], nums[right]);
            }
            left++;
            right++;
        }
    }
};