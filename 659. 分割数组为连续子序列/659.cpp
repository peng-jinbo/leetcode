class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        for(auto num:nums) m1[num]++;
        for(int i = 0; i < (int) nums.size(); i++)
        {
            if(m1.find(nums[i])!=m1.end())
            {
                if(m2.find(nums[i] -1) == m2.end())
                {
                    if(m1.find(nums[i]+1) != m1.end()&&m1.find(nums[i] + 2) != m1.end())
                    {
                        m2[nums[i]+2]++;
                        m1[nums[i]]--;
                        m1[nums[i]+1]--;
                        m1[nums[i]+2]--;
                        if(m1[nums[i]] == 0) m1.erase(nums[i]);
                        if(m1[nums[i]+1] == 0) m1.erase(nums[i]+1);
                        if(m1[nums[i]+2] == 0) m1.erase(nums[i]+2);
                    }
                    else
                    {
                        return false;
                    }
                }
                else{
                    m2[nums[i]-1]--;
                    m2[nums[i]]++;
                    m1[nums[i]]--;
                    if(m1[nums[i]] == 0) m1.erase(nums[i]);
                    if(m2[nums[i]-1] == 0) m2.erase(nums[i]-1);
                }
            }
        }
        return true;

    }
};