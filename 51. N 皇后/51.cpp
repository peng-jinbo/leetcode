class Solution {
public:
    vector<vector<string>> result;
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> xie(n, vector<int>(n,0));
        vector<string> temp;
        backtrack(n,0,temp,xie);
        return result;
    }
    void backtrack(int n, int row, vector<string> temp, vector<vector<int>>& xie)
    {
        if(row == n)
        {
            result.push_back(temp);
            return;
        }
        string s = string(n,'.');
        for(int i = 0; i < n; i++)
        {
            if(xie[row][i] == 0)
            {
                int count = 0;
                for(int j = row; j < n; j++)
                {
                    xie[j][i]++;
                    if(i+count < n) xie[j][i+count]++;
                    if(i-count >= 0) xie[j][i-count]++;
                    count++;
                }
                s[i] = 'Q';
                temp.push_back(s);
                backtrack(n,row+1,temp,xie);
                count = 0;
                for(int j = row; j < n; j++)
                {
                    xie[j][i]--;
                    if(i+count < n) xie[j][i+count]--;
                    if(i-count >= 0) xie[j][i-count]--;
                    count++;
                }
                s[i] = '.';
                temp.pop_back();
            }
        }
    }
};