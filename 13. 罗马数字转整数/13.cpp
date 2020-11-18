class Solution {
public:
    unordered_map<char,int> m;
    int romanToInt(string s) {
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int result = 0;
        int i = 0;
        while(i < s.length())
        {
            if(i < s.length() - 1)
            {
                if(m[s[i]] < m[s[i+1]])
                {
                    result += (m[s[i+1]] - m[s[i]]);
                    i += 2;
                }
                else
                {
                    result += m[s[i]];
                    i++;
                }
            }
            else{
                result += m[s[i]];
                i++;
            }
        }
        return result;
    }
};