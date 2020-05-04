bool isPossible(vector<int> &A, int &B, int minDistance)
{
    int lastPos = A[0];
    int NoOfCowsSet = 1;
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i] - lastPos >= minDistance)
        {
            NoOfCowsSet++;
            lastPos = A[i];
        }
    }
    return NoOfCowsSet >= B;
}

int Solution::solve(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    int left = 0, right = A.back() - A[0], mid = 0, ans;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (isPossible(A, B, mid))
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}