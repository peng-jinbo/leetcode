class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        char sign = '+';
        if(s[0] == '-') sign = '-';
        int num = 0;
        for(int i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if(isdigit(ch)) num = num*10 + (ch-'0');
            if((!isdigit(ch) && ch != ' ') || i == s.length()-1){
                if(sign == '+') stk.push(num);
                else if(sign == '-') stk.push(-num);
                else if(sign == '*')
                {
                    int pre = stk.top();
                    stk.pop();
                    stk.push(pre*num);
                }
                else if(sign == '/'){
                    int pre = stk.top();
                    stk.pop();
                    stk.push(pre/num);
                }
                num = 0;
                sign = ch;
            }
        }
        int result = 0;
        while(!stk.empty())
        {
            result += stk.top();
            stk.pop();
        }
        return result;
    }
    bool isdigit(char ch)
    {
        return ch >= '0' && ch <= '9';
    }
};