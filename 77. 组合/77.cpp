class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        backtrack(n,0,temp,k);
        return result;
    }
    void backtrack(int n, int pos, vector<int> temp, int k)
    {
        
        if(temp.size() == k)
        {
            result.push_back(temp);
            return;
        }
        if(temp.size() + (n-pos) < k) return;
        for(int i = pos+1; i <= n; i++)
        {
            temp.push_back(i);
            backtrack(n,i,temp,k);
            temp.pop_back();
        }
    }
private:
    vector<vector<int>> result;
};