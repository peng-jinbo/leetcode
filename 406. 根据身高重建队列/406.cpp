class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 从最小开始放，统计剩余位置
        int n = people.size();
        set<int> s;
        for(int i = 0; i < n; i++)
        {
            s.insert(i);
        }
        sort(people.begin(),people.end(),[&](vector<int> a, vector<int>b)
        {
            if(a[0] > b[0]) return false;
            else if(a[0] < b[0]) return true;
            else{
                if(a[1]<b[1]) return false;
                else return true;
            }
        });
        vector<vector<int>> result(n,vector<int> {0,0});
        for(int i = 0; i < n; i++)
        {
            auto iter = s.begin();
            for(int j= 0; j < people[i][1]; j++)
            {
                iter++;
            }
            result[*iter][0] = people[i][0];
            result[*iter][1] = people[i][1];
            s.erase(*iter);
        }
        return result;
    }
};