class Solution {
public:
    int max_num = pow(2,31) -1;
    bool isPalindrome(int x) {
        int record = x;
        if(x < 0) return false;
        int y = 0;
        while(x > 0)
        {
            if(y < max_num/10 ||(y == max_num/10 && x%10 <= 7))
            {
                y = y*10 + x%10;
                x = x/10;
            }
            else return false;
        }
        return record == y;
    }
};