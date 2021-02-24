class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0 || x == 1.0) return 1;
        if(x == 0.0 && n < 0) return x; // 当x是0而n是负数的时候，特殊情况
        double res = 1.0;
        long exp = n; // 必须是long，否则如果n=INT_MIN，-n就会越界
        if(n < 0)
        {
            x = 1 / x;
            exp = - exp;
        }
        while(exp)
        {
            // 快速幂方法（位运算）
            // 假如n=9，9写成二进制就是1001
            // 每当exp & 1 = 1的时候，就执行乘方运算
            if(exp & 1) res *= x;
            x *= x;
            exp >>= 1;
        }
        return res;
    }
};
