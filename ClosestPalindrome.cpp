string Solution::solve(string A) {
    int left = 0;
    int right = A.length()-1;
    int changesLeft = 1;
    while (left<=right)
    {
        if (A[left]!=A[right])
        {
            if (changesLeft>0)
            {
                changesLeft--;
            }
            else
            {
                return "NO";
            }
        }
        left++;
        right--;
    }
    if(changesLeft==1 && A.length()%2==0)
        return "NO";
    return "YES";
}
