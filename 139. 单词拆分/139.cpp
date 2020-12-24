class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(string word : wordDict)
        {
            st.insert(word);
        }
        vector<bool> dp(s.length()+1, false);
        dp[0] = true;
        for(int i = 1; i <= s.length(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(dp[j]&&st.find(s.substr(j, i-j)) != st.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
        

    }
};