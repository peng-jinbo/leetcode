
//法一
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1 == ""&&s2 == ""&&s3 == "") return true;
        int pos1 = 0;
        int pos2 = 0;
        int pos3 = 0;
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        while(pos3 < len3)
        {
            if(pos1 < len1&&pos2 < len2)
            {
                if(s1[pos1] == s3[pos3] && s2[pos2] != s3[pos3]) pos1++;
                else if(s1[pos1] != s3[pos3] && s2[pos2] == s3[pos3]) pos2++;
                else if(s1[pos1] != s3[pos3] && s2[pos2] != s3[pos3]) return false;
                else
                {
                    string new_s1 = s1.substr(pos1+1,len1);
                    string new_s2 = s2.substr(pos2+1,len2);
                    string new_s3 = s3.substr(pos3+1,len3);
                    if(isInterleave(new_s1,s2.substr(pos2,len2),new_s3)||isInterleave(s1.substr(pos1,len1),new_s2,new_s3)) return true;
                    else return false;
                }
            }
            else if(pos1<len1)
            {
                if(s1[pos1] == s3[pos3]) pos1++;
                else return false;
            }
            else if(pos2<len2)
            {
                if(s2[pos2] == s3[pos3]) pos2++;
                else return false;
            }
            else return false;
            pos3++;
        }
        if(pos1 == len1&&pos2 == len2) return true;
        else return false;
    }
};

//法二
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1 == ""&&s2 == ""&&s3 == "") return true;
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if(len1 + len2 != len3) return false;
        vector<vector<bool>> dp(len1+1,vector<bool>(len2+1,false));
        dp[0][0] = true;
        for(int i = 0; i <= len1; i++)
        {
            for(int j = 0; j <= len2; j++)
            {
                if(i>0) dp[i][j] = dp[i][j]||(dp[i-1][j]&&s1[i-1] == s3[i+j-1]);
                if(j > 0) dp[i][j] = dp[i][j]||(dp[i][j-1]&&s2[j-1] == s3[i+j-1]); 
            }
        }
        return dp[len1][len2];
    }
};