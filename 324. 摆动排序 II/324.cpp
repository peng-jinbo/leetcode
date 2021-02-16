class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int pos = (n -1) / 2;
        vector<int> result(n);
        int i = 0;
        while(i < nums.size()-1)
        {
            result[i] = nums[pos];
            result[i + 1] = nums[n-1];
            pos--;
            n--;
            i += 2;
        }
        if(i == nums.size()-1)
        {
            result[i] = nums[0];
        }
        nums = result;
    }
};