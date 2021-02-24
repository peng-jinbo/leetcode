class Solution {
public:
    int cuttingRope(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        int yushu = n%3;
        int num = n/3;
        if(yushu == 0) return pow(3,num);
        else if(yushu == 1) return pow(3,num-1) * 4;
        else return pow(3,num) * 2;
    }
};