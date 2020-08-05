int Solution::solve(vector<vector<int>> &A)
{
    int rows = A.size();
    int cols = A[0].size();
    int sumFromTop[rows + 1][cols + 1];
    memset(sumFromTop, 0, sizeof sumFromTop);
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            sumFromTop[row + 1][col + 1] = sumFromTop[row][col + 1] + sumFromTop[row + 1][col] - sumFromTop[row][col] + A[row][col];
        }
    }
    int ans = 0;
    for (int rowStart = 0; rowStart < rows; rowStart++)
    {
        for (int rowEnd = rowStart; rowEnd < rows; rowEnd++)
        {
            for (int colStart = 0; colStart < cols; colStart++)
            {
                for (int colEnd = colStart; colEnd < cols; colEnd++)
                {
                    ans = max(ans, sumFromTop[rowStart][colStart] + sumFromTop[rowEnd + 1][colEnd + 1] - sumFromTop[rowStart][colEnd + 1] - sumFromTop[rowEnd + 1][colStart]);
                }
            }
        }
    }
    return ans;
}
