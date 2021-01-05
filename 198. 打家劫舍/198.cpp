class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        int a = nums[0];
        int b = nums[1];
        int c = nums[2] + nums[0];
        for(int i = 3; i < n; i++)
        {
            int temp = c;
            c = nums[i] + max(a,b);
            a = b;
            b = temp;
        }
        return max(b,c);

    }
};