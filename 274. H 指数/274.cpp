class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int x = 0;
        for(int i = 0; i < nums.size(); i++) x = x^i^nums[i];
        x ^= nums.size();
        return x;
    }
};