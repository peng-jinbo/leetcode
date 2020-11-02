class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // 只要选中入度为0的点就行了
        vector<int> result;
        set<int> s;
        for(auto edge:edges)
        {
            s.insert(edge[1]);
        }
        while(n)
        {
            if(s.find(n-1) == s.end()) result.push_back(n-1);
            n--;
        }
        return result;
    }
};