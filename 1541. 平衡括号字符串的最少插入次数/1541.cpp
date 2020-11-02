class Solution {
public:
    int minInsertions(string s) {
        //栈记录左括号
        stack<char> left;
        int result = 0;
        for(int i = 0; i < s.length(); i++)
        {
            // 左括号直接入栈
            if(s[i] == '(')
            {
                left.push(s[i]);
            }
            else    //右括号两个地方要考虑
            {
                // 首先考虑是否到边界或者右边一位还是右括号，如果不是，则需要插入右括号
                if(i == s.length()-1 ||s[i+1]!=')')
                {
                    result++;
                }
                // 如果满足条件，则跳过下一个右括号
                else{
                    i++;
                }
                //再考虑左括号，如果栈空，则要插入一个左括号
                if(left.empty())
                {
                    result++;
                }
                // 否则直接出栈
                else{
                    left.pop();
                }
            }
        }
        // 最后判断左括号栈是否为空，不为空则每个左括号要插入两个右括号
        while(!left.empty())
        {
            result += 2;
            left.pop();
        }
        return result;
    }
};