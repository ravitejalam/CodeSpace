int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    int n = C.size(), maxi = 0;
    for (int i : A)
        maxi = max(maxi, i);
    int dp[maxi + 1];
    int oneWeightCost = INT_MAX;
    for (int i = 0; i < B.size(); i++)
        if (B[i] == 1)
            oneWeightCost = min(oneWeightCost, C[i]);
    for (int i = 0; i < maxi + 1; i++)
        dp[i] = i * oneWeightCost;

    for (int items = 1; items < n + 1; items++)
    {
        for (int size = 0; size < maxi + 1; size++)
        {
            dp[size] = size - B[items - 1] >= 0 ? min(dp[size - B[items - 1]] + C[items - 1], dp[size]) : dp[size];
        }
    }
    int ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        ans += dp[A[i]];
    }
    return ans;
}
