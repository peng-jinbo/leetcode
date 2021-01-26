class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0) return false;
        int m = matrix[0].size();
        int r = n-1;
        int c = 0;
        while(r >= 0 && c < m)
        {
            if(matrix[r][c] == target) return true;
            else if(matrix[r][c] < target) c++;
            else r--;
        }
        return false;
    }
};