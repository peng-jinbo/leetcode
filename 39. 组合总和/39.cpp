class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        backtrack(candidates,target,temp,0);
        return result;
    }
    void backtrack(vector<int>& candidates, int target, vector<int> temp,int num)
    {
        if(target == 0)
        {
            result.push_back(temp);
            return;
        }
        if(target<0) return;
        for(int i = num; i < candidates.size(); i++)
        {
            target -= candidates[i];
            temp.push_back(candidates[i]);
            backtrack(candidates,target,temp,i);
            target += candidates[i];
            temp.pop_back();
        }
    }
};