class Solution {
public:
    string countAndSay(int n) {
        string res = "";
        if(n == 1) return res + '1';
        string temp = countAndSay(n-1);
        int j = 0;
        while(j < temp.length())
        {
            int i = j;
            while(i < temp.length())
            {
                if(temp[i] == temp[j]) i++;
                else break;
            }
            res += to_string(i-j) + temp[j];
            j = i;
        }
        return res;

    }
};