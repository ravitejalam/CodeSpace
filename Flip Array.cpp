int Solution::solve(const vector<int> &A)
{
    int total = 0;
    for (int i : A)
        total += i;
    int n = A.size();
    int dp[n + 1][total + 1];
    memset(dp, 0, sizeof dp);
    for (int items = 0; items < n + 1; items++)
        for (int sum = 0; sum < total + 1; sum++)
            if (sum == 0 || items == 0)
                continue;
            else
            {
                int prev = sum - A[items - 1];
                if (prev >= 0 && (dp[items - 1][prev] > 0 || prev == 0))
                    dp[items][sum] = dp[items - 1][sum] ? min(1 + dp[items - 1][prev], dp[items - 1][sum]) : 1 + dp[items - 1][prev];
                else
                    dp[items][sum] = dp[items - 1][sum];
            }
    for (int sum = total / 2; sum >= 0; sum--)
        if (dp[n][sum])
            return dp[n][sum];
    return -1;
}