class Solution {
public:
    bool isAnagram(string s, string t) {
        // 哈希表
        unordered_map<char,int> m;
        for(auto ch:s)
        {
            m[ch] += 1;
        }
        for(auto ch : t)
        {
            if(m.find(ch) != m.end())
            {
                m[ch]--;
                if(m[ch] == 0)
                {
                    m.erase(ch);
                }
            }
            else
            {
                return false;
            }
        }
        if(m.size()!=0) return false;
        return true;
    }
};