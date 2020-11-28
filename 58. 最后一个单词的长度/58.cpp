class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int begin = len-1;
        int end = -1;
        while(begin >= 0)
        {
            if(s[begin] == ' ')
            {
                begin--;
            }
            else
            {
                break;
            }
        }
        end = begin;
        while(end >= 0)
        {
            if(s[end] != ' ') end--;
            else break;
        }
        return begin-end;
    }
};