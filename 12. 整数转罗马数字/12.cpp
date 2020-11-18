class Solution {
public:
    int num2char[7] = {1000,500,100,50,10,5,1};
    char ch[7] = {'M','D','C','L','X','V','I'};
    string intToRoman(int num) {
        int i = 0;
        string result = "";
        while(num > 0)
        {
            while(num >= num2char[i])
            {
                num -= num2char[i];
                result += ch[i];
            }
            if(i < 6)
            {
                if(i % 2 == 0)
                {
                    if(num >= num2char[i] - num2char[i+2])
                    {
                        result = result + ch[i+2] + ch[i];
                        num -= (num2char[i] - num2char[i+2]);
                    }
                }
                else
                {
                    if(num >= num2char[i] - num2char[i+1])
                    {
                        result = result + ch[i+1] + ch[i];
                        num -= (num2char[i] - num2char[i+1]);
                    }
                }
            }
            i++;
        }
        return result;
    }
};