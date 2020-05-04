int Solution::sqrt(int A) {
    int left = 0, right = 46340, mid = 0,ans=0;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        long long int sq =mid*mid;
        if (sq == A)
        {
            ans = mid;
            break;
        }
        else if (sq < A)
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
