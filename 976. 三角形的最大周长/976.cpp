class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        int result = 0;
        sort(A.begin(), A.end());
        for(int i = A.size()-1; i >= 0; i--)
        {
            int first = i -1;
            int last = i -2;
            if(last >= 0 && A[last] + A[first] > A[i])
            { 
                return A[last] + A[first] + A[i];
            }
        }
        return result;
    }
};