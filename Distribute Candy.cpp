int Solution::candy(vector<int> &A)
{
    vector<int> candies(A.size(), 1);
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i] > A[i - 1])
        {
            candies[i] = candies[i - 1] + 1;
        }
    }
    for (int i = A.size() - 2; i >= 0; i--)
    {
        if (A[i] > A[i + 1])
        {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < candies.size(); i++)
    {
        ans += candies[i];
    }
    return ans;
}