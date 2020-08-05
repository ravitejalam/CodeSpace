int Solution::minPathSum(vector<vector<int>> &A)
{
    int rows = A.size();
    int cols = A[0].size();
    int dp[rows][cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            dp[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = A[i][j];
            }
            else
            {
                if (j - 1 >= 0)
                {
                    dp[i][j] = min(dp[i][j], A[i][j] + dp[i][j - 1]);
                }
                if (i - 1 >= 0)
                {
                    dp[i][j] = min(dp[i][j], A[i][j] + dp[i - 1][j]);
                }
            }
        }
    }
    return dp[rows - 1][cols - 1];
}
