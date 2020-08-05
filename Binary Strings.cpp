int Solution::solve(string A, int B)
{
    int ans = 0;
    for (int i = 0; i < A.size() - B + 1; i++)
    {
        if (A[i] == '0')
        {
            for (int j = 0; j < B; j++)
            {
                if (A[i + j] == '1')
                    A[i + j] = '0';
                else
                    A[i + j] = '1';
            }
            ans++;
        }
    }
    for (int i = A.size() - B + 1; i < A.size(); i++)
    {
        if (A[i] == '0')
            return -1;
    }
    return ans;
}