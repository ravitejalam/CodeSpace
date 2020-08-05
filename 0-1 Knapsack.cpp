int Solution::solve(vector<int> &A, vector<int> &B, int C)
{
    int n = A.size();
    int dp[n + 1][C + 1];
    memset(dp, 0, sizeof dp);
    for (int items = 1; items < n + 1; items++)
    {
        for (int size = 0; size < C + 1; size++)
        {
            dp[items][size] = size - B[items - 1] >= 0 ? max(dp[items - 1][size - B[items - 1]] + A[items - 1], dp[items - 1][size]) : dp[items - 1][size];
        }
    }
    return dp[n][C];
}
