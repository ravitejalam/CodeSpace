int Solution::minimumTotal(vector<vector<int>> &A)
{
    int dp[A.size()][A[A.size() - 1].size()];
    memset(dp, 0, sizeof dp);
    dp[0][0] = A[0][0];
    for (int level = 1; level < A.size(); level++)
    {
        for (int index = 0; index < A[level].size(); index++)
        {
            dp[level][index] = A[level][index];
            int left = index - 1 >= 0 ? dp[level - 1][index - 1] : INT_MAX;
            int right = index < A[level - 1].size() ? dp[level - 1][index] : INT_MAX;
            dp[level][index] += min(left, right);
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < A[A.size() - 1].size(); i++)
    {
        ans = min(ans, dp[A.size() - 1][i]);
    }
    return ans;
}
