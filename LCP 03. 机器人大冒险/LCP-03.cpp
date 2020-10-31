class Solution {
public:
    // static bool mysort(vector<int> a, vector<int> b)
    // {
    //     return (a[0] + a[1]) < (b[0] + b[1]);
    // }
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        // sort(obstacles.begin(),obstacles.end(),mysort);
        // 统计command中”U“和”R“的个数，并且将小于command长度的各种个数情况保存
        int u_num = 0;
        int r_num = 0;
        int count = 0;
        unordered_map<int,vector<int>> m;
        for(int i = 0; i < command.length(); i++)
        {
            if(command[i] == 'U') u_num++;
            else r_num++;
            m[i] = {r_num,u_num};
        }
        // 判断障碍物是不是在路径上，判断方法为将障碍物的x，y按比例放到command的长度中，再按照记录结果判断
        for(auto obstacle : obstacles)
        {
            if(obstacle[0] <= x&& obstacle[1] <= y)
            {
                if(abs(obstacle[0]/r_num - obstacle[1]/u_num) <= 1)
                {
                    int min_num = min(obstacle[0]/r_num ,obstacle[1]/u_num);
                    int r_mod = obstacle[0] - min_num * r_num;
                    int u_mod = obstacle[1]- min_num * u_num;
                    if(r_mod == 0 && u_mod == 0) return false;
                    if(r_mod+u_mod-1>=command.length()) continue;
                    if(m[r_mod+u_mod-1][0] == r_mod && m[r_mod+u_mod-1][1] == u_mod) return false;
                    
                }
            }
        }
        // 判断能否到达终点，方法一样
        if(abs(x/r_num - y/u_num) <= 1)
        {
            int min_num = min(x/r_num ,y/u_num);
            int r_mod = x - min_num*r_num;
            int u_mod = y - min_num*u_num;
            if(r_mod == 0 && u_mod == 0) return true;
            if(r_mod+u_mod-1>=command.length()) return false;
            if(m[r_mod+u_mod-1][0] == r_mod && m[r_mod+u_mod-1][1] == u_mod) return true;
            
        }
        return false;
    }
};