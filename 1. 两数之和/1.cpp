class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>> m;
        for(int i = 0; i < nums.size(); i++)
        {
            m[nums[i]].push_back(i);
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(m.find(target-nums[i]) != m.end())
            {
                if(target-nums[i] != nums[i])
                {
                    return {i,m[target-nums[i]][0]};
                }
                else
                {
                    for(int j = 0; j < m[target-nums[i]].size(); j++)
                    {
                        if(m[target-nums[i]][j] != i)
                        {
                            return {i,m[target-nums[i]][j]};
                        }
                    }
                    
                }
            }
        }
        return {};
    }
};