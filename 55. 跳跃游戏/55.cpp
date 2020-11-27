class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1) return true;
        int pos = 0;
        while(pos < nums.size())
        {
            if(nums[pos] == 0) return false;
            int temp = 0;
            int tag = 0;
            for(int i = 1; i <= nums[pos]; i++)
            {
                if(i + pos >= nums.size()-1) return true;
                if(i + nums[i+pos] > temp)
                {
                    temp = i + nums[i+pos];
                    tag = i;
                }
            }
            pos = pos + tag;
        }
        return true;
    }
};