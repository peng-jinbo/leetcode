class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
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
            if(i > num && candidates[i] == candidates[i-1]) continue;
            target -= candidates[i];
            temp.push_back(candidates[i]);
            backtrack(candidates,target,temp,i+1);
            target += candidates[i];
            temp.pop_back();
        }
    }
};