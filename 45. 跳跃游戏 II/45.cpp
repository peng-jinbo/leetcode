class Solution {
public:
    int jump(vector<int>& nums) {
        int pos = 0;
        int sz = nums.size();
        int result = 0;
        while(pos < sz-1)
        {
            int temp = 0;
            int tag = pos;
            for(int i = 1; i <= nums[pos]; i++)
            {
                if(i + pos >= sz-1) return result+1;
                else
                {
                    if(i+nums[pos+i] > temp)
                    {
                        temp = i+nums[pos+i];
                        tag = pos + i;
                    }
                }
            }
            pos = tag;
            result++;
        }
        return result;
    }
};