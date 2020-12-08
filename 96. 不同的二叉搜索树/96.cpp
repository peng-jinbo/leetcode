class Solution {
public:
    int numTrees(int n) {
        vector<int> M(n+1,0);
        M[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            int temp = 0;
            for(int j = 1; j <= i; j++)
            {
                temp += M[j-1]*M[i-j];
            }
            M[i] = temp;
        }
        return M[n];
    }
};