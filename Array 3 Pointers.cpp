int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    int ans = INT_MAX;
    int i = 0, j = 0, k = 0;
    while (1)
    {
        int a = A[i];
        int b = B[j];
        int c = C[k];
        if(a==b && b==c)
            return 0;
        int mini = min(min(a,b),c);
        int maxi = max(max(a,b),c);
        ans  = min(ans,maxi-mini);
        if(a==mini && i<A.size())
            i++;
        else if(b==mini && j<B.size())
            j++;
        else if(c==mini && k<C.size())
            k++;
        else
            break;
    }
    return ans;
}