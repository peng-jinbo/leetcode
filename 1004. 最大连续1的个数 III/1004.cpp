class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int first = 0;
        int last = 0;
        int result = 0;
        bool tag = false;
        while(last < A.size())
        {
            if(A[last] == 0)
            {
                if(K)
                {
                    last++;
                    K--;
                }
                else
                {
                    tag = true;
                    result = max(result,last-first);
                    K += (1-A[first]);
                    first++;
                }
            }
            else{
                last++;
            }
        }
        if(A[A.size()-1] == 1) result = max(result, last-first);
        if(!tag) result = A.size();
        return result;
    }
};