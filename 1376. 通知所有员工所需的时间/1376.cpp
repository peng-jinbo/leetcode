class Solution {
public:
    // 存结点,dfs
    vector<vector<int>> son;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        son = vector<vector<int>> (n);
        for (int i = 0; i < n; i ++){
            if (i != headID){
                son[manager[i]].push_back(i);
            }
        }
        return dfs(headID, informTime);
    }

    int dfs(int u, vector<int>& informTime){
        int res = 0;
        for (auto s : son[u]) res = max(res, dfs(s, informTime));
        return res + informTime[u];
    }
};

