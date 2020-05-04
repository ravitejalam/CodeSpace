int Solution::solve(vector<int> &A) {
    int chunks = 0;
    int maxNum = INT_MIN;
    for (int i = 0; i < A.size(); i++)
    {
        maxNum = max(maxNum,A[i]);
        if(maxNum==i){
            chunks++;
        }
    }
    return chunks;
}
