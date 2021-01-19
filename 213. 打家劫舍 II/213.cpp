class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[1], nums[0]);
        if(n == 3) return max(nums[0], max(nums[1],nums[2]));
        int a = nums[0];
        int b = nums[1];
        int c = nums[2] + nums[0];
        int temp;
        for(int i = 3; i < n-1; i++)
        {
            temp = c;
            c = max(a,b) + nums[i];
            a = b;
            b = temp;
        }
        int result1 = max(c,b);
        a = nums[1];
        b = nums[2];
        c = nums[3] + nums[1];
        for(int i = 4; i < n; i++)
        {
            temp = c;
            c = max(a,b) + nums[i];
            a = b;
            b = temp;
        }
        int result2 = max(c,b);
        return max(result1,result2);
    }
};