class Solution {
public:
    vector<vector<int>> renew{{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n,vector<int>(n,-1));
        int num = 1;
        int l = 0;
        int r = n;
        int t = 0;
        int b = n;
        while(num <= n*n)
        {
            for(int i = l; i < r; i++)
            {
                result[t][i] = num;
                num++;
            }
            t++;
            for(int i = t; i < b; i++)
            {
                result[i][r-1] = num;
                num++;
            }
            r--;
            for(int i = r-1; i >= l; i--)
            {
                result[b-1][i] = num;
                num++;
            }
            b--;
            for(int i = b-1; i >= t; i--)
            {
                result[i][l] = num;
                num++;
            }
            l++;

        }
        return result;
    }
};