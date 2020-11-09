class Solution {
public:
    int primePalindrome(int N) {
        // 偶数位的回文数不可能是素数，以此跳过一些数的判别
        for(int i = N; i < 2*pow(10,8); i++)
        {
            if(i > 11 && (int(log10(i)) + 1) % 2 == 0) 
            {
                i = pow(10,int(log10(i)) + 1);
            }
            if(isPalindrome(i) == i&&isPrime(i)) return i;
        }
        return 0;
    }
    bool isPrime(int N)
    {
        if(N < 2) return false;
        for(int i = 2; i <= sqrt(N); i++)
        {
            if(N%i == 0) return false;
        }
        return true;
    }
    int isPalindrome(int N)
    {
        int res = 0;
        while(N > 0)
        {
            res = res*10 + N%10;
            N = N/10;
        }
        return res;
    }
};