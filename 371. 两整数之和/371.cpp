class Solution {
public:
    int getSum(int a, int b) {
        int remain = a^b;
        unsigned int up_bit = a&b;
        while(up_bit != 0){
            up_bit <<= 1;
            a = remain;
            b = up_bit;
            remain = a ^ b;
            up_bit = a & b;
        }
        return remain;
    }
};