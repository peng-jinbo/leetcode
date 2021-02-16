class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        int num = log2(n)/log2(3);
        return pow(3,num) == n||pow(3,num-1) == n||pow(3,num+1) == n;

    }
};