class Solution {
public:
    // 先用map记录每一个bank中以及start中只改变一位就能完成的突变
    // 再利用回溯找到可能的路径以及对应的修改次数
    int result = -1;
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_map<string,vector<string>> m;
        for(int i = 0; i < bank.size(); i++)
        {
            for(int j = 0; j < bank.size(); j++)
            {
                if(bank[i]!=bank[j]&&cal_distance(bank[i],bank[j]))
                {
                    m[bank[i]].push_back(bank[j]);
                }
            }
        }
        for(int i = 0; i < bank.size(); i++)
        {
            if(start!=bank[i]&&cal_distance(start,bank[i])) m[start].push_back(bank[i]);
        }
        set<string> s;
        backtrack(m,s,start,end,0);
        return result;
    }
    void backtrack(unordered_map<string,vector<string>>& m,set<string>& s, string temp, string end,int count)
    {
        if(temp == end)
        {
            if(result == -1)
            {
                result = count;
            }
            else{
                result = min(result,count);
            }
            return;
        }
        s.insert(temp);
        for(auto mid:m[temp])
        {
            if(s.find(mid) == s.end())
            {
                backtrack(m,s,mid,end,count+1);
            }
        }
        s.erase(temp);
    }
    bool cal_distance(string word1, string word2)
    {
        int num = 0;
        for(int i = 0; i < word1.length(); i++)
        {
            if(word1[i] != word2[i])
            {
                if(num == 1)
                {
                    return false;
                }
                else
                {
                    num++;
                }
            }
        
        }
        return true;
    }
};