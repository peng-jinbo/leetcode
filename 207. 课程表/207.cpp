class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degree(numCourses,0);
        vector<int> temp{};
        unordered_map<int,vector<int>> graph;
        for(int i = 0; i < prerequisites.size(); i++)
        {
            if(graph.find(prerequisites[i][1]) == graph.end()) graph[prerequisites[i][1]] = temp;
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degree[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
        {
            if(degree[i] == 0) q.push(i);
        }
        int visited = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            visited++;
            for(int num:graph[node])
            {
                degree[num]--;
                if(degree[num] == 0) q.push(num);
            }
            graph.erase(node);
        }
        return visited == numCourses;
        
    }
};