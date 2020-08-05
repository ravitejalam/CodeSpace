int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C, int D)
{
    int maxSweetness[D + 1];
    int N = A.size();
    memset(maxSweetness, 0, sizeof maxSweetness);
    for (int packets = 0; packets < N; packets++)
    {
        for (int cost = 1; cost <= D; cost++)
        {
            if (cost - C[packets] >= 0)
                maxSweetness[cost] = max(maxSweetness[cost - C[packets]] + B[packets] * A[packets], maxSweetness[cost]);
        }
    }
    return maxSweetness[D];
}
