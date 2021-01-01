class Solution {
public:
    string convertToTitle(int n) {
        string result = "";
        while(n > 0)
        {
            result = char('A' + (n-1)%26) + result;
            n = (n-1)/26;
        }
        return result;
    }
};