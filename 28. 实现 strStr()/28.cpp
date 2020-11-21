class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if(m == 0) return 0;
        for(int i = 0; i <= n-m; i++)
        {
            if(haystack[i] == needle[0])
            {
                bool tag = true;
                for(int j = 0; j < m; j++)
                {
                    if(haystack[i+j]!=needle[j])
                    {
                        tag = false;
                        break;
                    }
                }
                if(tag) return i;
            }
        }
        return -1;
    }
};