int Solution::solve(string A, string B)
{
    int dp[A.length() + 1][B.length() + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i < A.length() + 1; i++)
    {
        for (int j = 1; j < B.length() + 1; j++)
        {
            if (B[j - 1] == A[i - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(max(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]);
            }
        }
    }
    return dp[A.length()][B.length()];
}