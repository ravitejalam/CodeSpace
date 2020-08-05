int Solution::bulbs(vector<int> &A)
{
    int ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if ((A[i] + (ans % 2)) % 2 == 0)
            ans++;
    }
    return ans;
}