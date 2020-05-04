void sudoku(vector<vector<char>> &A, vector<vector<bool>> &row, vector<vector<bool>> &col, vector<vector<vector<bool>>> &block, int index, bool &done, vector<vector<char>> &ans)
{
    if (index == 81)
    {
        done = true;
        ans = A;
        return;
    }
    int I = index / 9, J = index % 9;
    if (A[I][J] == '.')
    {
        for (int i = 1; i < 10 and !done; i++)
        {
            if (!row[I][i - 1] and !col[J][i - 1] and !block[I / 3][J / 3][i - 1]){
                row[I][i - 1] = true;
                col[J][i - 1] = true;
                block[I / 3][J / 3][i - 1] = true;
                A[I][J] = '0' + i;
                sudoku(A, row, col, block, index + 1, done, ans);
                A[I][J] = '.';
                row[I][i - 1] = false;
                col[J][i - 1] = false;
                block[I / 3][J / 3][i - 1] = false;
            }
        }
    }
    else
    {
        sudoku(A, row, col, block, index + 1, done, ans);
    }
}

void Solution::solveSudoku(vector<vector<char>> &A)
{
    vector<vector<char>> ans;
    vector<vector<bool>> row(9, vector<bool>(9, false)), col(9, vector<bool>(9, false));
    vector<vector<vector<bool>>> block(3, vector<vector<bool>>(4, vector<bool>(9, false)));
    bool done = false;
    for (int i = 0; i < 81; i++)
    {
        int I = i / 9, J = i % 9;
        if (A[I][J] != '.')
        {
            row[I][A[I][J] - '1'] = true;
            col[J][A[I][J] - '1'] = true;
            block[I / 3][J / 3][A[I][J] - '1'] = true;
        }
    }
    sudoku(A, row, col, block, 0, done, ans);
    A = ans;
}