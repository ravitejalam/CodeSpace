int Solution::minCut(string A)
{
    int n = A.length();
    bool isPalindrome[n][n];
    int minCuts[n][n];
    memset(isPalindrome, false, sizeof isPalindrome);
    memset(minCuts, 0, sizeof minCuts);
    for (int size = 1; size <= n; size++)
    {
        for (int start = 0; start + size - 1 < n; start++)
        {
            int end = start + size - 1;
            if (size == 1)
                isPalindrome[start][end] = true;
            else if (A[start] == A[end])
            {
                if (size == 2)
                    isPalindrome[start][end] = true;
                else if (isPalindrome[start + 1][end - 1])
                    isPalindrome[start][end] = true;
            }
        }
    }
    for (int size = 1; size <= n; size++)
    {
        for (int start = 0; start + size - 1 < n; start++)
        {
            int end = start + size - 1;
            if (!isPalindrome[start][end])
            {
                int mini = INT_MAX;
                for (int split = start; split < end; split++)
                {
                    mini = min(mini, minCuts[start][split] + minCuts[split + 1][end] + 1);
                }
                minCuts[start][end] = mini;
            }
        }
    }
    return minCuts[0][n - 1];
}
