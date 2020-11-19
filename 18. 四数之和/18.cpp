class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        int temp;
        for(int first = 0; first < sz; first++)
        {
            if(first > 0 && nums[first] == nums[first-1]) continue;
            temp = nums[first];
            for(int second = first+1; second < sz; second++)
            {
                if(second > first+1 && nums[second] == nums[second-1]) continue;
                int forth = sz - 1;
                for(int third = second + 1; third < sz; third++)
                {
                    if(third > second + 1 && nums[third] == nums[third-1]) continue;
                    while(third < forth && temp + nums[third] + nums[forth] + nums[second] > target)
                    {
                        forth--;
                    }
                    if(third == forth) break;
                    if(temp + nums[third] + nums[forth] + nums[second] == target)
                    {
                        result.push_back({nums[first],nums[second],nums[third],nums[forth]});
                    }
                }
            }
        }
        return result;
    }
};