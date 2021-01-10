class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(n == m) return n;
        while(n > 0)
        {
            
            n = n&(n-1);
            if(n <= m && n!=0) 
            {
                return n;

            }
            
        }
        return 0;
    }
};