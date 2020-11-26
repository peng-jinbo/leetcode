class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return; 
        transpose(matrix);
        for(int col = 0; col < n/2; col++)
        {
            for(int row = 0; row < n; row++)
            {
                swap(matrix[row][col], matrix[row][n-col-1]);
            }
        }
    }
    void transpose(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};