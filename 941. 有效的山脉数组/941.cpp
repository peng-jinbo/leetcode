class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int n = A.size();
        if(n < 3) return false;
        if(A[0]>=A[1]) return false;
        int tag = n - 2;
        for(int i = 1; i < n-1; i++)
        {
            if(A[i] <= A[i-1])
            {
                tag = i-1;
                break;
            }
        }
        for(int j = tag+1; j < n; j++)
        {
            if(A[j] >= A[j-1]) return false;
        }
        return true;
    }
};