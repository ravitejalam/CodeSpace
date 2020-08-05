int Solution::maxProduct(const vector<int> &A)
{
    vector<int> preFixSum;
    int ans = *min_element(A.begin(), A.end());
    int MaxPositive = INT_MIN;
    int MaxNegative = INT_MIN;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == 0)
        {
            MaxPositive = INT_MIN;
            MaxNegative = INT_MIN;
            ans = max(ans, 0);
        }
        else
        {
            if (MaxNegative != INT_MIN)
                MaxNegative *= A[i];
            if (MaxPositive == INT_MIN)
                MaxPositive = A[i];
            else
                MaxPositive *= A[i];
            if (A[i] < 0)
                swap(MaxPositive, MaxNegative);
        }
        ans = max(ans, MaxPositive);
    }
    return ans;
}