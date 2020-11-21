class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int n = words.size();
        if(n == 0) return result;
        int z = words[0].length();
        int len = s.length();
        unordered_map<string,int> m;
        unordered_map<string,int> temp;
        string s_temp;
        for(string word:words)
        {
            m[word] += 1;
        }
        for(int i = 0; i <= len-(z*n); i++)
        {
            temp = m;
            for(int j = 0; j < n; j++)
            {
                s_temp = s.substr(i+j*z,z);
                if(temp.find(s_temp) != temp.end())
                {
                    temp[s_temp]--;
                    if(temp[s_temp] == 0) temp.erase(s_temp);
                }
                else break;
            }
            if(temp.size() == 0) result.push_back(i);
        }
        return result;
    }
};