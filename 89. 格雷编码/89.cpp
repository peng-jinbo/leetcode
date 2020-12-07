class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(pow(2,n),-1);
        result[0] = 0;
        if(n == 0) return result;
        result[1] = 1;
        int pos = 2;
        for(int i = 1; i < n; i++)
        {
            int temp = 1<<i;
            for(int j = pow(2,i)-1; j >= 0; j--)
            {
                result[pos] = result[j] + temp;
                pos++;
            }
        }
        return result;
    }
};