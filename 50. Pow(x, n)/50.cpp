class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        bool tag = false;
        int nn;
        if(n < 0)
        {
            tag = true;
            if(n != -2147483648)
                nn = -1*n;
            else nn = 2147483647;
        }
        double res = mypositivePow(x, nn);
        if(tag)
        {
            if(n == -2147483648)
                res = 1/(res*x);
            else
                res = 1/res;
        }
        return res;
    }
    double mypositivePow(double x, int n)
    {
        if(n == 0) return 1;
        long temp = 1;
        double res = x;
        while(temp*2 <= n)
        {
            res *= res;
            temp+=temp;
        }
        return res * mypositivePow(x, n-temp);
    }
    
};