class Solution {
public:
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<bool>> dp(len,vector<bool>(len,false));
        for(int i = 0; i < len; i++)
        {
            for(int j = i; j >= 0; j--)
            {
                if(j == i) dp[j][i] = true;
                else
                {
                    if(s[i] != s[j]) dp[j][i] = false;
                    else dp[j][i] = (i-j == 1||dp[j+1][i-1]);
                }
            }
        }
        vector<string> temp;

        dfs(s, temp, 0, dp);
        return result;

    }

    void dfs(string s, vector<string> temp, int begin, vector<vector<bool>>& dp)
    {
        if(begin >= s.length())
        {
            result.push_back(temp);
            return;
        }
        for(int i = begin; i < s.length(); i++)
        {
            if(!dp[begin][i]) continue;
            temp.push_back(s.substr(begin,i-begin+1));
            dfs(s,temp,i+1,dp);
            temp.pop_back();
        }
    }

private:
    vector<vector<string>> result;
};