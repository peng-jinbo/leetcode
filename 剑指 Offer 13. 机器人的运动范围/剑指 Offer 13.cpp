class Solution {
public:
    int get_sum(int num){
        int res = 0;
        while(num > 0){
            res += num%10;
            num = num/10;
        }
        return res;
    }
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push(pair(0,0));
        int result = 0;
        visited[0][0] = true;
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            result++;
            if(row > 0 && !visited[row-1][col] && get_sum(row-1) + get_sum(col) <= k) q.push(pair(row-1,col)), visited[row-1][col] = true;
            if(row < m-1 && !visited[row+1][col] && get_sum(row+1) + get_sum(col) <= k) q.push(pair(row+1,col)), visited[row+1][col] = true;
            if(col > 0 && !visited[row][col-1] && get_sum(row) + get_sum(col-1) <= k) q.push(pair(row,col-1)), visited[row][col-1] = true;
            if(col < n-1 && !visited[row][col+1] && get_sum(row) + get_sum(col+1) <= k) q.push(pair(row,col+1)), visited[row][col+1] = true;
        }
        return result;
    }
};