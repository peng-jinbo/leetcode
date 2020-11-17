class Solution {
public:
    int max_num = pow(2,31)-1;
    int reverse(int x) {
        bool tag = false;
        if(x < 0)
        {
            if(x == -pow(2,31)) return 0;
            else
            {
                tag = true;
                x = -x;
            }
        }
        int result = 0;
        while(x > 0)
        {
            
            if(result <= (max_num-x%10)/10)
            {
                result = result* 10 + x%10;
                x = x/10;
            }
            else return 0;
        }
        if(tag) result = -1*result;
        return result;
    }
};