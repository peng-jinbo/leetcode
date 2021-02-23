class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        if(n == 0) return false;
        int m = board[0].size();
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(backtrack(board, word,0,i, j)) return true;
            }
        }
        return false;
    }
    bool backtrack(vector<vector<char>>& board, string word, int pos, int i, int j)
    {
        if(i>=board.size()||i<0||j>=board[0].size()||j<0||word[pos] != board[i][j]) return false;
        if(pos == word.length()-1)
        {
            return true;
        }
        char temp = board[i][j];
        board[i][j] = '/';
        if(backtrack(board, word, pos+1,i+1,j)) return true;
        if(backtrack(board, word, pos+1,i-1,j)) return true;
        if(backtrack(board, word, pos+1,i,j+1)) return true;
        if(backtrack(board, word, pos+1,i,j-1)) return true;
        board[i][j] = temp;
        return false;
    }
};