int Solution::solve(vector<int> &A)
{
    if (A.empty())
        return 0;
    vector<unordered_map<int, int>> dp(A.size());

    int res = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if ((long)A[i] - (long)A[j] > INT_MAX || (long)A[i] - (long)A[j] < INT_MIN)
                continue;
            int dif = A[i] - A[j];
            dp[i][dif] += 1;
            dp[i][dif] += dp[j][dif];
            res += dp[j][dif];
        }
    }
    return res;
}
