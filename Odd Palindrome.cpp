#define mod 1000000007

vector<int> Solution::solve(string A)
{
    int n = A.length();
    long long int dp[n][n];
    memset(dp, 0, sizeof dp);
    for (int len = n - 1; len >= 0; --len)
    {
        for (int i = 0; i + len < n; ++i)
        {
            int j = i + len;
            if (i == 0 and j == n - 1)
            {
                dp[i][j] = A[i] == A[j] ? 2 : 1;
            }
            else
            {
                dp[i][j] += i - 1 >= 0 ? dp[i - 1][j] : 0;
                dp[i][j] %= mod;
                dp[i][j] += j + 1 <= n - 1 ? dp[i][j + 1] : 0;
                dp[i][j] %= mod;
                if (A[i] == A[j])
                    dp[i][j] += i - 1 < 0 or j + 1 >= n ? 1 : 0;
                else if (i - 1 >= 0 and j + 1 <= n - 1)
                    dp[i][j] -= dp[i - 1][j + 1];
                dp[i][j] = (mod + dp[i][j]) % mod;
            }
        }
    }
    vector<int> ways;
    for (int i = 0; i < n; ++i)
    {
        if (i == 0 or i == n - 1)
            ways.push_back(1);
        else
            ways.push_back(dp[i - 1][i + 1]);
    }
    return ways;
}
