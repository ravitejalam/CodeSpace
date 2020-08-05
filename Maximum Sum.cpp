int Solution::solve(vector<int> &A, int B, int C, int D)
{
    int first = INT_MIN;
    int second = INT_MIN;
    int third = INT_MIN;
    for (int i = 0; i < A.size(); i++)
    {
        first = max(first, A[i] * B);
        second = max(second, first + A[i] * C);
        third = max(third, second + A[i] * D);
    }
    return third;
}