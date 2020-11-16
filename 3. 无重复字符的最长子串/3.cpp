class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        set<char> vec;
        int first = 0;
        int last = 0;
        while(last < s.length())
        {
            if(vec.find(s[last]) == vec.end())
            {
                vec.insert(s[last]);
                last++;
            }
            else
            {
                if(result < last-first)
                {
                    result = last-first;
                }
                while(s[first] != s[last])
                {
                    vec.erase(s[first]);
                    first++;
                }
                vec.erase(s[first]);
                first++;
            }
        }
        if(result<last-first)
        {
            result = last -first;
        }
        return result;
    }
};