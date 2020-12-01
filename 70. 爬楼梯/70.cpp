class Solution {
public:
    int climbStairs(int n) {
        int a = 1;
        int b = 1;
        while(n >= 2)
        {
            int temp = b;
            b = a + b;
            a = temp;
            n--;
        }
        return b;
    }
};