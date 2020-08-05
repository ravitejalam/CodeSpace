int dp[20001];

int getMaxSum(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        if (i == 0)
            dp[i] = A[i];
        else if (i == 1)
            dp[i] = max(A[i], A[i - 1]);
        else
            dp[i] = max(A[i] + dp[i - 2], dp[i - 1]);
    }
    return dp[A.size() - 1];
}

int Solution::adjacent(vector<vector<int>> &A)
{
    vector<int> a;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < A[0].size(); i++)
        a.push_back(max(A[0][i], A[1][i]));
    return getMaxSum(a);
}