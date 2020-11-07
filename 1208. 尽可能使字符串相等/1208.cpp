class Solution {
public:
    // 滑动窗口 两个指针
    int equalSubstring(string s, string t, int maxCost) {
        int l = 0;
        int r = 0;
        int cost = 0;
        while(r < s.length())
        {
            while(maxCost - (abs(int(s[r]-t[r]))) >= 0 && r<s.length())
            {
                maxCost -= (abs(int(s[r]-t[r])));
                r++;
            }
            maxCost+= (abs(int(s[l]-t[l])));
            l++;
            maxCost -= (abs(int(s[r]-t[r])));
            r++;
        }
        return r-l;
    }
};