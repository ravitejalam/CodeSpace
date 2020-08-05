int Solution::numDecodings(string A)
{
    if (A.size() == 0)
        return 0;
    if (A[0] == '0')
        return 0;
    int dp[A.size() + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= A.size(); i++)
    {
        if (A[i - 1] != '0')
        {
            dp[i] = dp[i - 1];
        }
        if ((A[i - 2] == '1') || (A[i - 2] == '2' && A[i - 1] <= '6' && A[i - 1] >= '0'))
        {
            dp[i] += dp[i - 2];
        }
    }
    return dp[A.size()];
}