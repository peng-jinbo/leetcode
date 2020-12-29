class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for(char ch : s)
        {
            result = result * 26 + (ch-'A' + 1);
        }
        return result;
    }
};