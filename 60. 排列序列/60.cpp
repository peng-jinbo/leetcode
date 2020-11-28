class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> valid(n + 1, 1);
        vector<int> fa;
        fa.push_back(1);
        for(int i = 1; i < n; i++)
        {
            fa.push_back(fa[i-1] * i);
        }
        string result = "";
        k--;
        int s = n;
        while(s > 0)
        {
            int order = k/fa[s-1] + 1;
            for(int i = 1; i <=n; i++)
            {
                order -= valid[i];
                if(order == 0)
                {
                    result += (i+'0');
                    valid[i]= 0;
                    break;
                }
            }
            k = k%fa[s-1];
            s--;
        }
        return result;
    }
};