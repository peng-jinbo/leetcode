class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        for(int i = 0; i < n; i++)
        {
            if(A[i][0] == 0)
            {
                for(int j = 0; j < m; j++)
                {
                    A[i][j] = A[i][j]^1;
                }
            }
        }
        int result = 0;
        for(int i = 0; i < m; i++)
        {
            int temp = 0;
            for(int j = 0; j < n; j++)
            {
                if(A[j][i] == 1) temp++;
            }
            int num = max(temp,n-temp);
            result += num*(1<<(m-i-1));
        }
        return result;
    }
};