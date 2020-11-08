class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        vector<int> v(n+1,0);
        v[0] = 0;
        v[1] = 1;
        int result = 0;
        for(int i = 2; i <= n; i++)
        {
            if(i % 2 == 0)
            {
                v[i] = v[i/2];
            }
            else
            {
                v[i] = v[i/2] + v[i/2+1];
            }
            result = max(result,v[i]);
        }
        return result;
    }
};