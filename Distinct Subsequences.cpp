int Solution::numDistinct(string A, string B)
{
    long long int dp[A.length() + 1][B.length() + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < A.length() + 1; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i < A.length() + 1; i++)
    {
        for (int j = 1; j < B.length() + 1; j++)
        {
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            dp[i][j] += dp[i - 1][j];
        }
    }
    return dp[A.length()][B.length()];
}
