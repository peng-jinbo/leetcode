class Solution {
public:
    long long div(long long a,long long b){
        if(a == b) return 1;
        if(a < b) return 0;
        long long temp = b,res = 1;
        while(a > b+b){
            b += b;
            res += res;
        }
        res += div(a-b,temp);
        return res;
    }
    
    int divide(int dividend, int divisor) {
        long long a = abs(dividend*1ll), b = abs(divisor*1ll);
        long long res = div(a,b);
        if((dividend ^ divisor) < 0) res = -res; 
        if(res >= INT_MAX) return INT_MAX;
        if(res <= INT_MIN) return INT_MIN;
        return res;
    }
};