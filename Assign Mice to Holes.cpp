int Solution::mice(vector<int> &A, vector<int> &B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int maxi = 0;
    for (int i = 0; i < A.size(); i++)
    {
        maxi = max(maxi, abs(A[i] - B[i]));
    }
    return maxi;
}
