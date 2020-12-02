class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0) return;
        int m = matrix[0].size();
        set<int> s_row;
        set<int> s_col;
        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < m; col++)
            {
                if(matrix[row][col] == 0)
                {
                    s_row.insert(row);
                    s_col.insert(col);
                }
            }
        }
        for(auto index:s_row)
        {
            for(int col = 0; col < m; col++)
            {
                matrix[index][col] = 0;
            }
        }
        for(auto index:s_col)
        {
            for(int row = 0; row < n; row++)
            {
                matrix[row][index] = 0;
            }
        }
        return;
    }
};