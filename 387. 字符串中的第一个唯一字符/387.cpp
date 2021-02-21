class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(26,0);
        for(auto ch:s)
        {
            count[ch-'a']++;
        }
        for(int i=0; i < s.length(); i++)
        {
            if(count[s[i]-'a'] == 1) return i;
        }
        return -1;
    }
};