int Solution::solve(string A)
{
    int l = A.length();
    int dp[l][l];
    memset(dp, 0, sizeof dp);
    for (int s = 1; s <= l; s++)
    {
        for (int i = 0; i < l - s + 1; i++)
        {
            int j = s + i - 1;
            if (s == 1)
                dp[i][j] = 1;
            else if (A[i] == A[j])
            {
                if (s == 2)
                    dp[i][j] = 2;
                else
                    dp[i][j] = 2 + dp[i + 1][j - 1];
            }
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][l - 1];
}
