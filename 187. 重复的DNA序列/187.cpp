class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> seen; //记录存在过的子字符串
        vector<string> result;  
        set<string> res;    //记录重复出现过的子字符串
        if(s.length()<10) return result;
        for(int i = 0; i <= s.length()-10; i++) //滑动窗口
        {
            if(seen.find(s.substr(i,10)) == seen.end())
            {
                seen.insert(s.substr(i,10));
            }
            else
            {
                res.insert(s.substr(i,10));
            }
        }
        for(auto str : res) //写入result
        {
            result.push_back(str);
        }
        return result;
    }
};