int Solution::solve(vector<int> &A) {
    int count = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if(A[i]!=i){
            int tmp = A[i];
            A[i]=A[tmp];
            A[tmp]=tmp;
            count++;
            i--;
        }
    }
    return count;
}