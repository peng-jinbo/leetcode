class Solution {
private:
    vector<int> presum = vector<int>(20002);
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size());
        for(int i = nums.size()-1; i >= 0; i--)
        {
            result[i] = get_sum(nums[i]);
            update(nums[i]);
        }
        return result;
    }
    void update(int x)
    {
        x += 10001;
        while(x < presum.size())
        {
            presum[x] += 1;
            x += x&(-x);
        }
    }
    int get_sum(int x)
    {
        x += 10000;
        int result = 0;
        while(x > 0)
        {
            result += presum[x];
            x -= x&(-x);
        }
        return result;
    }
};