class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        priority_queue<int> q1;
        priority_queue<int> q2;
        for(auto ch:word1)
        {
            m1[ch]++;
        }
        for(auto ch:word2)
        {
            m2[ch]++;
        }
        for(auto m:m1)
        {
            if(m2.find(m.first) == m2.end()) return false;
            q1.push(m.second);
        }
        for(auto m:m2)
        {
            q2.push(m.second);
        }
        while(!q1.empty()&&!q2.empty())
        {
            if(q1.top()!=q2.top()) return false;
            else
            {
                q1.pop();
                q2.pop();
            }
        }
        if(!q1.empty()||!q2.empty()) return false;
        return true;
        
    }
};