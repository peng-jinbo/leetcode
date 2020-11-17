class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string result = "";
        int pos;
        for(int i = 0 ; i < numRows; i++)
        {
            pos = i;
            int j = 0;
            while(pos < s.length())
            {
                result += s[pos];
                if(i == 0 || i == numRows-1) pos += (2*numRows-2);
                // else if(i < numRows/2)
                // {
                //     if(j == 0)
                //     {
                //         pos += (2*numRows-2*i-2);
                //         j = 1;
                //     }
                //     else{
                //         pos += 2*i;
                //         j = 0;
                //     }
                // }
                else{
                    if(j == 0)
                    {
                        pos += (2*numRows-2*i-2);
                        j = 1;
                    }
                    else{
                        pos += 2*i;
                        j = 0;
                    }
                }
            }
        }
        return result;
    }
};