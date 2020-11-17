class Solution {
public:
    int max_num = pow(2,31) -1;
    int min_num = -1 * pow(2,31);
    int myAtoi(string str) 
    {
        int pos = 0;
        bool tag;
        while(pos < str.length())
        {
            if(str[pos] == ' ') pos++;
            else if(str[pos] == '+')
            {
                tag = false;
                pos++;
                break;
            }
            else if(str[pos] == '-')
            {
                tag = true;
                pos++;
                break;
            }
            else if(str[pos] <= '9' && str[pos] >= '0')
            {
                tag = false;
                break;
            }
            else{
                return 0;
            }
        }
        int result = 0;
        while(pos < str.length())
        {
            if(str[pos] <= '9' && str[pos] >= '0')
            {
                if(tag == false)
                {
                    if(result < max_num/10 || (result == max_num/10 && int(str[pos] - '0') <= 7))
                    {
                        result = result * 10 + int(str[pos] - '0');
                    }
                    else{
                        return max_num;
                    }
                }
                else{
                    if(result  > (min_num/10)||(result == (min_num/10) && int(str[pos] - '0') <= 8))
                    {
                        result = result * 10 - int(str[pos] - '0');
                    }
                    else return min_num;
                }
            }
            else{
                break;
            }
            pos++;
        }
        return result;
    }
};