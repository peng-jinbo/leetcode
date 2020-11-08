class Solution {
public:
    int minDeletions(string s) {
        if(s.length() == 1) return 0;
        unordered_map<char,int> m;
        for(char ch:s)
        {
            m[ch] += 1;
        }
        set<int> ss;
        int result = 0;
        for(auto mm : m)
        {
            if(ss.find(mm.second) == ss.end())
            {
                ss.insert(mm.second);
            }
            else
            {
                while(ss.find(mm.second) != ss.end() && mm.second != 0)
                {
                    mm.second--;
                    result++;
                }
                ss.insert(mm.second);
            }
        }
        return result;
        
    }
};