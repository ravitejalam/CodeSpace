int Solution::coinchange2(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    int sum = B + 1;
    int dp[sum];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for (int coin = 0; coin < A.size(); coin++)
    {
        for (int i = 1; i < sum; i++)
        {
            dp[i] = (A[coin] <= i) ? (dp[i] + dp[i - A[coin]]) % 1000007 : dp[i];
        }
    }
    return dp[B];
}