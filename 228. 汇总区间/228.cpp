class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.size() == 0) return result;
        int start = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i]!=1 + nums[i-1])
            {
                if(nums[i-1] != start)
                    result.push_back(to_string(start) + "->" + to_string(nums[i-1]));
                else result.push_back(to_string(start));
                start = nums[i];
            }
        }
        if(nums[nums.size()-1] != start)
            result.push_back(to_string(start) + "->" + to_string(nums[nums.size()-1]));
        else result.push_back(to_string(start));
        return result;
    }
};