class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 先找到需要交换的数字对，再将后面的部分逆序
        int n = nums.size();
        if(n <= 1) return;
        int tag = -1;
        for(int i = n-1; i>= 0; i--)
        {
            for(int j = n-1; j >i; j--)
            {
                if(nums[i] < nums[j])
                {
                    swap(nums[i], nums[j]);
                    tag = i;
                    break;
                }
            }
            if(tag != -1) break;
        }
        tag++;
        n--;
        while(tag < n)
        {
            swap(nums[tag],nums[n]);
            tag++;
            n--;
        }
    }
};