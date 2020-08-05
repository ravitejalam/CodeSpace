int Solution::minDistance(string A, string B)
{
    int dp[A.length() + 1][B.length() + 1];
    for (int i = 0; i < A.length() + 1; i++)
    {
        for (int j = 0; j < B.length() + 1; j++)
        {
            if (i == 0 or j == 0)
            {
                dp[i][j] = max(i, j);
            }
            else if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
    }
    return dp[A.length()][B.length()];
}
