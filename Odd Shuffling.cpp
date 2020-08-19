int binarySearch(vector<int> &A, int B)
{
    int l = 0, r = A.size() - 1;
    if (r % 2 == 1)
        r--;
    int ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (mid % 2 == 1)
            mid += 1;
        if (A[mid] > B)
        {
            r = mid - 2;
        }
        else if (A[mid] <= B)
        {
            ans = mid;
            l = mid + 2;
        }
    }
    return ans;
}

int Solution::solve(vector<int> &A, int B)
{
    int k = 0, n = A.size();

    int ans = binarySearch(A, B);

    if (ans == -1 || A[ans] == B || ans + 1 == n)
        return ans;

    ans++;

    int val = A[ans], ind = -1;
    if (val == B)
        return ans;

    ind = binarySearch(A, val);

    ind++;
    if (A[ind] == B)
        return ind;
    return -1;
}
