class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) return 0;
        int m = matrix[0].size();
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 || j == 0)
                {
                    result = max(result,matrix[i][j]-'0');
                }
                else if(matrix[i][j] == '0') continue;
                else{
                    matrix[i][j] = min(matrix[i-1][j]-'0',min(matrix[i-1][j-1]-'0',matrix[i][j-1]-'0')) + '1';
                    result = max(result,matrix[i][j]-'0');
                }
            }
        }
        return result*result;
    } 
    
};