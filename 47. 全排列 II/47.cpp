class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> visited(nums.size(),false);
        vector<int> temp;
        sort(nums.begin(),nums.end());
        backtrack(nums,0,temp,visited);
        return result;
    }
    void backtrack(vector<int>& nums, int len,vector<int> temp, vector<bool>& visited)
    {
        if(len == nums.size())
        {
            result.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(visited[i] ||(i>0&&nums[i] == nums[i-1]&&!visited[i-1])) continue;
            temp.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums,len+1,temp,visited);
            visited[i] = false;
            temp.pop_back();

        }
    }
};