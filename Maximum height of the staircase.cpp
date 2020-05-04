int Solution::solve(int A) {
    int left = 0, right = ceil(sqrt(2*A)+1), mid,ans=0;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (((mid*(mid+1))/2) == A)
        {
            ans = mid;
            break;
        }
        else if (((mid*(mid+1))/2) < A)
        {
            ans=mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}
