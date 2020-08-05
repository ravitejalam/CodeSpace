int Solution::calculateMinimumHP(vector<vector<int>> &A)
{
    int rows = A.size();
    int cols = A[0].size();
    int dp[rows][cols];
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            dp[row][col] = INT_MAX;
        }
    }
    bool flag = true;
    for (int row = rows - 1; row >= 0; row--)
    {
        for (int col = cols - 1; col >= 0; col--)
        {
            if (flag)
            {
                flag = false;
                dp[row][col] = A[row][col] < 0 ? abs(A[row][col]) + 1 : 1;
            }
            else
            {
                if (col + 1 < cols)
                {
                    if (A[row][col] < 0)
                    {
                        dp[row][col] = min(dp[row][col], dp[row][col + 1] - A[row][col]);
                    }
                    else
                    {
                        dp[row][col] = min(dp[row][col], A[row][col] + 1 >= dp[row][col + 1] ? 1 : dp[row][col + 1] - A[row][col]);
                    }
                }
                if (row + 1 < rows)
                {
                    if (A[row][col] < 0)
                    {
                        dp[row][col] = min(dp[row][col], dp[row + 1][col] - A[row][col]);
                    }
                    else
                    {
                        dp[row][col] = min(dp[row][col], A[row][col] + 1 >= dp[row + 1][col] ? 1 : dp[row + 1][col] - A[row][col]);
                    }
                }
            }
        }
    }
    return dp[0][0];
}
