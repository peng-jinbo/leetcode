class Solution {
public:
    bool isUgly(int num) {
        if(num == 0) return false;
        bool flag = true;
        while(flag && num != 1)
        {
            if(num % 2 == 0) num /= 2;
            else if(num % 3 == 0) num /= 3;
            else if(num % 5 == 0) num /= 5;
            else flag = false;
        }
        return num == 1 ? true: false;
    }
};