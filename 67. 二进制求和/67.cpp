class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length();
        int m = b.length();
        int num = 0;
        string result = "";
        while(n > 0 && m > 0)
        {
            int count = (a[n-1] - '0') + (b[m-1] - '0') +num;
            if(count >= 2)
            {
                num = 1;
                result = to_string(count-2) + result;
            }
            else
            {
                num = 0;
                result = to_string(count) + result;
            }
            n--;
            m--;
        }
        int tag = m == 0?n:m;
        string temp = m==0?a:b;
        while(tag > 0)
        {
            int count = (temp[tag-1] - '0') +num;
            if(count >= 2)
            {
                num = 1;
                result = to_string(count-2) + result;
            }
            else
            {
                num = 0;
                result = to_string(count) + result;
            }
            tag--;
        }
        if(num == 1)
        {
            result = '1' + result;
        }
        return result;
    }
};