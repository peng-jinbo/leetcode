class Solution {
private:
    vector<vector<int>> result;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        backtrack(nums,-1,temp);
        return result;
    }
    void backtrack(vector<int>& nums, int pos, vector<int> temp)
    {
        if(pos >= 0&&pos >= nums.size()) return;
        result.push_back(temp);
        for(int i = pos + 1; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
            backtrack(nums,i,temp);
            temp.pop_back();
        }
    }
};