class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0;
        int r = nums.size()-1;
        while(l <= r)
        {
            if(nums[l] == val)
            {
                while(l <= r && nums[r] == val)
                {
                    r--;
                }
                if(l <= r)
                {
                    swap(nums[r], nums[l]);
                    r--;
                }
                else break;
            }
            l++;
        }
        return l;

    }
};