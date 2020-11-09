class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // 大顶堆维护k个最小的值
        int n = points.size();
        priority_queue<pair<int, int>> q;
        for(int i = 0; i < K; i++)
        {
            int dist = pow(points[i][0],2)+pow(points[i][1],2);
            q.emplace(dist,i);
        }
        for(int j = K; j<n; j++)
        {
            int dist = pow(points[j][0],2)+pow(points[j][1],2);
            if(q.top().first>=dist)
            {
                q.pop();
                q.emplace(dist,j);
            }
        }
        vector<vector<int>> result;
        while(!q.empty())
        {
            result.push_back(points[q.top().second]);
            q.pop();
        }
        return result;
    }
};