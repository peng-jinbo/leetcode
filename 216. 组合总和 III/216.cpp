class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        backtrack(k,n,temp, 0);
        return result;
    }
    void backtrack(int count, int num, vector<int>& temp, int tag)
    {
        if(count == 0)
        {
            if(num == 0) 
            {
                result.push_back(temp);
                return;
            }
            else return;
        }
        for(int i = tag+1; i <= 9; i++)
        {
            temp.push_back(i);
            backtrack(count-1,num-i,temp, i);
            temp.pop_back();
        }
    }

private:
    vector<vector<int>> result;
};