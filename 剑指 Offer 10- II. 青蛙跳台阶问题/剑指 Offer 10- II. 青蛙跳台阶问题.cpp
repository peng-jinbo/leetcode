class Solution {
public:
    int numWays(int n) {
        if(n == 0) return 1;
        if(n == 1) return 1;
        int a = 1;
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