int Solution::isMatch(const string A, const string B)
{
    int dp[B.length() + 1][A.length() + 1];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (int i = 0; i < B.length(); i++)
        dp[i + 1][0] = B[i] == '*' ? dp[i - 1][0] : 0;
    for (int i = 0; i < B.length(); i++)
    {
        for (int j = 0; j < A.length(); j++)
        {
            switch (B[i])
            {
            case '*':
                dp[i + 1][j + 1] = (B[i - 1] == '.') ?: (dp[i + 1][j] && B[i - 1] == A[j]) || dp[i - 1][j + 1] || dp[i][j + 1];
                break;
            case '.':
                dp[i + 1][j + 1] = dp[i][j];
                break;
            default:
                dp[i + 1][j + 1] = (B[i] == A[j]) ? dp[i][j] : 0;
                break;
            }
        }
    }
    return dp[B.length()][A.length()];
}