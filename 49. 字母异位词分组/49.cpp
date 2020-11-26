class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> m;
        for(auto str:strs)
        {
            string temp = str;
            sort(temp.begin(),temp.end());
            if(m.find(temp) == m.end()) m[temp] = {};
            m[temp].push_back(str);
        }
        for(auto mm:m)
        {
            result.push_back(mm.second);
        }
        return result;
    }
};