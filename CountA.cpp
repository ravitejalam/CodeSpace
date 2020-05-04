int Solution::solve(string A) {
    int count = 0;
    for (int i = 0; i < A.length(); i++)
    {
        if(A[i]=='a')
            count++;
    }
    return (count*(count+1))/2;
}