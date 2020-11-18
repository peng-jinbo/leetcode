class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int pos = 0;
        char temp = '-';
        string result = "";
        if(strs.size() == 0) return result;
        while(pos < strs[0].length())
        {
            for(int i = 0; i < strs.size(); i++)
            {
                if(pos < strs[i].length())
                {
                    if(temp == '-') temp = strs[i][pos];
                    else
                    {
                        if(temp != strs[i][pos]) return result;
                    }
                }
                else return result;
            }
            result += temp;
            pos++;
            temp = '-';
        }
        return result;
    }
};