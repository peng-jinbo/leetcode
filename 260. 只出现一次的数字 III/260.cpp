class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long x = 0;
        for(int num:nums)
        {
            x ^= num;
        }
        int y = x;
        x = x&(-x);
        int r1 = 0;
        for(int num:nums)
        {
            if(x&num)
            {
                r1 ^= num;
            }
        }
        vector<int> result{r1,y^r1};
        return result;
    }
};