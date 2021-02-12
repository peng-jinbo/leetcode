class Solution {
public:
    int hammingDistance(int x, int y) {
        int a = x ^ y;
        int result = 0;
        while(a)
        {
            a = a&(a-1);
            result++;
        }
        return result;
    }
};