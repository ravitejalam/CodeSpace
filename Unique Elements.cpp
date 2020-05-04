int Solution::solve(vector<int> &A) {
    sort(A.begin(),A.end());
    int count = 0;
    for (int i = 1; i < A.size(); i++)
    {
        if(A[i]==A[i-1]){
            count++;
            A[i]++;
        }
        else if(A[i]<A[i-1])
        {
            count+=A[i-1]-A[i]+1;
            A[i]=A[i-1]+1;
        }
    }
    return count;
}