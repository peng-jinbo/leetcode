class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for(int num:nums)
        {
            sum += num;
        }
        if(sum < x) return -1;
        int result = -1;
        int l = 0; 
        int r = 0;
        int count = 0;
        while(r < nums.size())
        {
            count += nums[r];
            if(count == sum-x)
            {
                if(result == -1)
                {
                    result = l + nums.size() -r-1;
                }
                else result = result<l + nums.size() -r-1?result:l + nums.size() -r-1;
                r++;
            }
            else if(count < sum-x)
            {
                r++;
            } 
            else{
                while(count > sum-x)
                {
                    count-=nums[l];
                    l++;
                }
                if(count == sum-x)
                {
                    if(result == -1)
                    {   
                        result = l + nums.size() -r-1;
                    }
                    else result = result<l + nums.size() -r-1?result:l + nums.size() -r-1;
                }
                r++;
            }
        }
        return result;
    }
};