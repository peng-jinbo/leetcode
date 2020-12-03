class Solution {
private:
    bool result = false;
    int dir[4][4]={{-1,0},{1,0},{0,-1},{0,1}};
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i = 0; i < n&&!result; i++)
        {
            for(int j = 0; j < m&&!result; j++)
            {
                if(board[i][j] == word[0])
                {
                    visited[i][j] = true;
                    backtrack(board,0,word,visited,i,j);
                }
            }
        }
        return result;
    }
    void backtrack(vector<vector<char>>& board, int pos, string& word, vector<vector<bool>>& visited ,int row, int col)
    {
        if(result) return;
        if(pos >= word.length()) return;
        if(pos == word.length()-1&&word[pos] == board[row][col])
        {
            result = true;
            return;
        }
        if(word[pos] != board[row][col]) return;
        visited[row][col] = true;
        for(int i = 0; i < 4&&!result; i++)
        {
            row += dir[i][0];
            col += dir[i][1];
            if(row >= 0&&row<board.size()&&col>=0&&col<board[0].size()&&!visited[row][col])
                backtrack(board,pos+1,word,visited,row,col);
            row -= dir[i][0];
            col -= dir[i][1];
        }
        visited[row][col] = false;
    }
};