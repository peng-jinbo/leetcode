class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        if(n == 0) return result;
        string temp = "";
        backtrack(0,temp,n,0);
        return result;
    }
    void backtrack(int l_count, string temp, int& n, int num)
    {
        if(num == 2 * n && l_count == 0)
        {
            result.push_back(temp);
            return;
        }
        if(l_count < 0 || num > 2*n || l_count > n)
        {
            return;
        }
        backtrack(l_count + 1, temp+'(',n, num+1);
        backtrack(l_count - 1, temp + ')',n, num+1);
    }
};