class Solution {
public:
    string smallestSubsequence(string text) {
        unordered_map<char,int> m;
        set<char> st;
        for(auto ch:text)
        {
            m[ch] += 1;
        }
        stack<char> s;
        for(auto ch:text)
        {
            m[ch] -= 1;
            if(s.empty())
            { 
                s.push(ch);
                st.insert(ch);
            }
            else
            {
                if(st.find(ch) == st.end())
                {
                    while(!s.empty() && ch < s.top() && m[s.top()] > 0)
                    {
                        st.erase(s.top());
                        s.pop();
                    }
                    s.push(ch);
                    st.insert(ch);
                }
            }
        }
        string result = "";
        while(!s.empty())
        {
            result = s.top() + result;
            s.pop();
        }
        return result;
    }
};