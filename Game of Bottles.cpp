int Solution::solve(vector<int> &A) {
    int count = 0;
    sort(A.begin(),A.end());
    int curr_count = 1;
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i]==A[i-1])
        {
            curr_count++;
        }
        else
        {
            count=max(count,curr_count);
            curr_count=1;
        }
    }
    count=max(count,curr_count);
    return count;
}
