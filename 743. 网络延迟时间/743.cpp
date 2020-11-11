class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        const int INF = 0x3f3f3f3f;
        vector<vector<int>> graph(N+1,vector<int>(N+1,-1));
        for(int i = 0; i < times.size(); i++)
        {
            graph[times[i][0]][times[i][1]] = times[i][2];
            // graph[times[i][0]][times[i][0]] = 0;
            // graph[times[i][1]][times[i][1]] = 0;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        vector<int> dist(N+1, INF);
        vector<bool> s(N+1,false);
        dist[K] = 0;
        q.emplace(0,K);
        while(q.size() != 0)
        {
            int node = q.top().second;
            int dis = q.top().first;
            q.pop();
            if(s[node]) continue;
            s[node] = true;
            for(int i = 1; i <= N; i++)
            {
                if(graph[node][i] != -1)
                {
                    if(graph[node][i] + dis <dist[i])
                    {
                        dist[i] = graph[node][i] + dis;
                        q.emplace(dist[i],i);
                    }
                }
            }
        }
        int ans = *max_element(dist.begin()+1, dist.end());
        return ans == INF ? -1: ans;

    }
};