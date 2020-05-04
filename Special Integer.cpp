bool check(vector<long long int> &A, int subArraySize, int B)
{
    for (long long int i = subArraySize - 1; i < A.size(); i++)
    {
        long long int prevSum = i - subArraySize < 0 ? 0 : A[i - subArraySize];
        if (A[i] - prevSum > B)
            return false;
    }
    return true;
}

int Solution::solve(vector<int> &A, int B)
{
    int s = A.size(), left = 1, right = s, mid = 0, ans = 0;
    vector<long long int> preComputedSum(s,A[0]);
    for (int i = 1; i < s; i++)
    {
        preComputedSum[i] = preComputedSum[i - 1] + A[i];
    }

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (check(preComputedSum, mid, B))
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