int Solution::solve(vector<int> &A, vector<int> &B)
{
    int ans = -1;
    for (int q = 1; q < A.size(); q++)
    {
        int minCost = 0;
        for (int p = 0; p < q; p++)
        {
            if (A[p] < A[q])
            {
                if (minCost == 0 || B[p] < minCost)
                {
                    minCost = B[p];
                }
            }
        }
        if (minCost > 0)
        {
            int minCost2 = 0;
            for (int r = q + 1; r < A.size(); r++)
            {
                if (A[r] > A[q])
                {
                    if (minCost2 == 0 || B[r] < minCost2)
                    {
                        minCost2 = B[r];
                    }
                }
            }
            if (minCost2 > 0)
            {
                if (ans == -1 || ans > (minCost + B[q] + minCost2))
                {
                    ans = minCost + B[q] + minCost2;
                }
            }
        }
    }
    return ans;
}