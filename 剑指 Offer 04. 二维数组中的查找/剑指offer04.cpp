class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) return false;
        int m = matrix[0].size();
        int i = n-1;
        int j = 0;
        while(i >= 0 && j < m)
        {
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] > target) i--;
            else j++;
        }
        return false;
    }
};