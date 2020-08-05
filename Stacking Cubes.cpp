int Solution::solve(int A)
{
    int ans = 0;
    for (int i = 1; i < A; i++)
    {
        if (A % i == 0)
            ans++;
    }
    return ans;
}