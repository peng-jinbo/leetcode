class Solution {
public:
    int numDecodings(string s) {
        int len = s.length();
        if(s[0] == '0') return 0;
        int a = 1;
        int b = 1;
        for(int i = 1; i < len; i++)
        {
            int temp = b;
            if(s[i] == '0')
            {
                if(s[i-1] == '1' || s[i-1] == '2') b = a;
                else return 0;
            }
            else if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
            {
                b = a + b;
            }
            a = temp;
        } 
        return b;
    }
};