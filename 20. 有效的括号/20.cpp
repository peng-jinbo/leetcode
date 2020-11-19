class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char ch:s)
        {
            if(ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else
            {
                if(st.empty()) return false;
                if(int(ch - st.top()) == 1 || int(ch - st.top()) == 2)
                {
                    st.pop();
                }
                else return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};