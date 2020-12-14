class Solution {
public:
    bool isPalindrome(string s) {
        if(s == "") return true;
        string temp = "";
        for(char ch:s)
        {
            if((ch >='0'&&ch<='9')||(ch >='a'&&ch<='z'))
            {
                temp += ch;
            }
            else if((ch >='A'&&ch<='Z'))
            {
                temp += (ch+32);
            }
        }
        int begin = 0;
        int end = temp.length()-1;
        while(begin < end)
        {
            if(temp[begin] != temp[end]) return false;
            begin++;
            end--;
        }
        return true;
    }
};