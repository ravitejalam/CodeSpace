int Solution::solve(vector<int> &A) {
    int s = A.size(), left = 0, right = s - 1, mid;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (mid & 1)
        {
            if (A[mid] == A[mid - 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        else
        {
            if (A[mid] == A[mid + 1])
            {
                left = mid + 2;
            }
            else
            {
                right = mid;
            }
        }
    }
    return A[(left+right)/2];
}
