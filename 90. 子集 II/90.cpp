class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<bool> visited(n,false);
        sort(nums.begin(),nums.end());
        backtrack(nums,visited,0,temp);
        return result;
    }
    void backtrack(vector<int>& nums, vector<bool>& visited, int pos, vector<int> temp)
    {
        // if(pos >= (int)nums.size()) return;
        result.push_back(temp);
        for(int i = pos; i < nums.size(); i++)
        {
            if(i > pos&&nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            visited[i] = true;
            backtrack(nums,visited,i+1,temp);
            temp.pop_back();
            visited[i] = false;
        }
    }
private:
    vector<vector<int>> result;
};