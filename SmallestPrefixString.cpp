string Solution::smallestPrefix(string A, string B) {
    int l = 1;
    while (l<=A.length())
    {
        if(A[l]>=B[0])
            break;
        l++;
    }
    return A.substr(0,l)+B[0];
}