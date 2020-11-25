class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,set<char>> row;
        unordered_map<int,set<char>> col;
        unordered_map<int,set<char>> square;
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    if(row.find(i) == row.end()) row[i].insert(board[i][j]);
                    else
                    {
                        if(row[i].find(board[i][j]) != row[i].end()) return false;
                        else row[i].insert(board[i][j]);
                    }
                    if(col.find(j) == col.end()) col[j].insert(board[i][j]);
                    else
                    {
                        if(col[j].find(board[i][j]) != col[j].end()) return false;
                        else col[j].insert(board[i][j]);
                    }
                    int num = 3*(j/3)+(i/3);
                    if(square.find(num) == square.end()) square[num].insert(board[i][j]);
                    else{
                        if(square[num].find(board[i][j])!=square[num].end()) return false;
                        else square[num].insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }
};