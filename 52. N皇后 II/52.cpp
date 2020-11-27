class Solution {
public:
    int result = 0;
    int totalNQueens(int n) {
        vector<vector<int>> xie(n, vector<int>(n,0));
        backtrack(n,0,xie);
        return result;
    }
    void backtrack(int n, int row, vector<vector<int>>& xie)
    {
        if(row == n)
        {
            result++;
            return;
        }
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
                backtrack(n,row+1,xie);
                count = 0;
                for(int j = row; j < n; j++)
                {
                    xie[j][i]--;
                    if(i+count < n) xie[j][i+count]--;
                    if(i-count >= 0) xie[j][i-count]--;
                    count++;
                }
            }
        }
    }
};