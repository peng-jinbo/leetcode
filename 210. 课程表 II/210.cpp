class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degree(numCourses,0);
        vector<vector<int>> graph(numCourses);
        for(auto prerequisit:prerequisites)
        {
            degree[prerequisit[0]] += 1;
            graph[prerequisit[1]].push_back(prerequisit[0]);
        }
        int count = 0;
        queue<int> q;
        vector<int> result;
        for(int i = 0; i < numCourses; i++)
        {
            if(degree[i] == 0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(int node1:graph[node])
            {
                degree[node1] -= 1;
                if(degree[node1] == 0)
                {
                    q.push(node1);
                }
            }
            result.push_back(node);
            count++;
        }
        if(count != numCourses)
        {
            result.clear();
        }
        return result;
    }
};