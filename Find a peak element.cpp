int Solution::solve(vector<int> &A) {
    int s = A.size(), left = 0, right = s - 1, mid = 0, index = -1;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        bool rightCond = A[mid] >= A[min(mid+1,right)];
        bool leftCond = A[mid] >= A[max(mid-1,left)];
        if (leftCond && rightCond)
        {
            index = mid;
            break;
        }
        else if (!rightCond and leftCond)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return A[index];
}
