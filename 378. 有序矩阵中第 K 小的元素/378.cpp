class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int begin = matrix[0][0];
        int end = matrix[n-1][m-1];
        while(begin < end){
            int mid = (begin + end)/2;
            int result = get_size(matrix, mid);
            if(result >= k) end = mid;
            else begin = mid+1;
        }
        return end;

    }

    int get_size(vector<vector<int>>& matrix, int num){
        int n = matrix.size();
        int m = matrix[0].size();
        int result = 0;
        int i = n-1;
        int j = 0;
        while(i >= 0 && j < m)
        {
            if(matrix[i][j] <= num) j++;
            else{
                i--;
                result += j;
            }
        }
        if(j == m) result += (i*m + j);
        return result;
    }
};