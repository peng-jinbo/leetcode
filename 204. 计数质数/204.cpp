class Solution {
public:
    int countPrimes(int n) {
        if(n == 0 || n == 1) return 0;
        vector<bool> record(n,false);
        int pos = 2;
        record[0] = true;
        record[1] = true;
        while(pos < n)
        { 
            if(!record[pos])
            {
                for(int i = 2; pos*i<n; i++)
                {
                    record[pos*i] = true;
                }
            }
            pos++;
        }
        int result = 0;
        for(int i = 0; i < n; i++)
        {
            if(!record[i]) result++;
        }
        return result;
    }
};