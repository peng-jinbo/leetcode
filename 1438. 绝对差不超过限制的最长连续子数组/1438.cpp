class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int first = 0;
        int last = 0;
        map<int,int> m;
        int result = 0;
        while(last < nums.size())
        {
            m[nums[last]]++;
            while(m.rbegin()->first - m.begin()->first > limit)
            {
                m[nums[first]]--;
                if (m[nums[first]] == 0) {
                    m.erase(nums[first]);
                }
                first++;
            }
            result = max(result,last-first+1);
            last++;
        }
        return result;
    }
};