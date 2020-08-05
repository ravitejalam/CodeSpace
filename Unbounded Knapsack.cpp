int Solution::solve(int A, vector<int> &B, vector<int> &C)
{
    int n = B.size();
    int dp[n + 1][A + 1];
    memset(dp, 0, sizeof dp);
    for (int items = 1; items < n + 1; items++)
    {
        for (int size = 0; size < A + 1; size++)
        {
            dp[items][size] = size - C[items - 1] >= 0 ? max(dp[items][size - C[items - 1]] + B[items - 1], dp[items - 1][size]) : dp[items - 1][size];
        }
    }
    return dp[n][A];
}
