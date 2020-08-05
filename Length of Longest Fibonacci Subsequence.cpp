int Solution::solve(vector<int> &A)
{
    int n = A.size();
    unordered_set<int> S(A.begin(), A.end());

    int maxLen = 0, x, y;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            x = A[j];
            y = A[i] + A[j];
            int length = 2;

            while (S.find(y) != S.end())
            {
                int z = x + y;
                x = y;
                y = z;
                maxLen = max(maxLen, ++length);
            }
        }
    }

    return maxLen >= 3 ? maxLen : 0;
}