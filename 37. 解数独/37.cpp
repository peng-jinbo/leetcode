class Solution {
public:
    bool valid = false;
    vector<int> pos;
    vector<vector<bool>> visited_row = vector<vector<bool>>(9,vector<bool>(9,false));
    vector<vector<bool>> visited_col = vector<vector<bool>>(9,vector<bool>(9,false));
    vector<vector<bool>> visited_square = vector<vector<bool>>(9,vector<bool>(9,false));
    void solveSudoku(vector<vector<char>>& board) {
        // vector<vector<bool>> visited_row(9,vector<bool>(9,false));
        // vector<vector<bool>> visited_col(9,vector<bool>(9,false));
        // vector<vector<bool>> visited_square(9,vector<bool>(9,false));
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    visited_row[i][board[i][j]-'0'-1] = true;
                    visited_col[j][board[i][j]-'0'-1] = true;
                    visited_square[i/3*3+j/3][board[i][j]-'0'-1] = true;
                }
                else{
                    pos.push_back(i*9+j);
                }
            }
        }
        backtrack(board, 0);
    }
    void backtrack(vector<vector<char>>& board, int num)
    {
        if(num >= pos.size()) 
        {
            valid = true;
            return;
        }
        else{
            int temp = pos[num];
            for(int i = 0; i < 9 && !valid; i++)
            {
                if(!visited_col[temp%9][i] && !visited_row[temp/9][i] && !visited_square[(temp/9)/3*3+(temp%9)/3][i])
                {
                    visited_col[temp%9][i] = true;
                    visited_row[temp/9][i] = true;
                    visited_square[(temp/9)/3*3+(temp%9)/3][i] = true;
                    board[temp/9][temp%9] = i + '0'+1;
                    backtrack(board,num+1);
                    visited_col[temp%9][i] = false;
                    visited_row[temp/9][i] = false;
                    visited_square[(temp/9)/3*3+(temp%9)/3][i] = false;
                }
            }
        }
    }
};