int Solution::anytwo(string A)
{
    int dpSize = A.length() + 1;
    int dp[dpSize][dpSize];
    for (int row = 0; row < dpSize; row++)
    {
        for (int col = 0; col < dpSize; col++)
        {
            if (row == 0 || col == 0)
                dp[row][col] = 0;
            else if (A[row - 1] == A[col - 1] && row != col)
                dp[row][col] = dp[row - 1][col - 1] + 1;
            else
                dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]);
        }
    }
    return dp[dpSize - 1][dpSize - 1] > 1 ? 1 : 0;
}