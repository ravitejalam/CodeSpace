int mergeSort(vector<long> &b, int lower, int upper, int low, int high)
{
    if (high - low <= 1)
        return 0;
    int mid = (low + high) / 2, m = mid, n = mid, count = 0;
    count = mergeSort(b, lower, upper, low, mid) + mergeSort(b, lower, upper, mid, high);
    for (int i = low; i < mid; i++)
    {
        while (m < high && b[m] - b[i] < lower)
            m++;
        while (n < high && b[n] - b[i] <= upper)
            n++;
        count += n - m;
    }
    inplace_merge(b.begin() + low, b.begin() + mid, b.begin() + high);
    return count;
}

int Solution::solve(vector<int> &A, int B, int C)
{
    int len = A.size();
    vector<long> sum(len + 1, 0);
    for (int i = 0; i < len; i++)
        sum[i + 1] = sum[i] + A[i];
    return mergeSort(sum, B, C, 0, len + 1);
}