class Solution {
public:
    // 回溯即可
    int result = 0;
    int countArrangement(int N) {
        vector<bool> visited(N+1,false);
        backtrack(N,visited,1);
        return result;
    }
    void backtrack(int N, vector<bool>& visited, int num)
    {
        if(num == N+1)
        {
            result++;
            return;
        }
        for(int i = 1; i <= N; i++)
        {
            if(!visited[i]&&((i%num == 0)||(num%i == 0)))
            {
                visited[i] = true;
                backtrack(N, visited,num+1);
                visited[i] = false;
            }
        }
    }
};