class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int a = 0;
        int b = 1;
        while(n > 1)
        {
            int temp = b;
            b = (a%1000000007 + b%1000000007)%1000000007;
            a = temp;
            n--;
        }
        return b;
    }
};