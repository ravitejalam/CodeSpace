int Solution::uniquePathsWithObstacles(vector<vector<int>> &A)
{
    int n = A.size();
    int m = A[0].size();
    int dp[n][m];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = (A[0][0] == 0) ? 1 : 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 0)
            {
                dp[i][j] += (i - 1 >= 0 && A[i - 1][j] == 0) ? dp[i - 1][j] : 0;
                dp[i][j] += (j - 1 >= 0 && A[i][j - 1] == 0) ? dp[i][j - 1] : 0;
            }
        }
    }
    return dp[n - 1][m - 1];
}
