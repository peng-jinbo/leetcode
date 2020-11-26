class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n,false);
        vector<int> temp;
        backtrack(nums,visited,n,temp);
        return result;
    }
    void backtrack(vector<int>& nums, vector<bool>& visited, int& n, vector<int> temp)
    {
        if(temp.size() == n)
        {
            result.push_back(temp);
            return;
        }
        for(int i = 0; i < n; i++)
        {
            if(visited[i]) continue;
            temp.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums,visited,n,temp);
            temp.pop_back();
            visited[i] = false;
        }
    }
};