int Solution::solve(vector<int> &A, int B) {
    int left = 0;
    int right = A.size()-1;
    int count = 0;
    while (left<right)
    {
        int sum = A[left]+A[right];
        if(sum<B)
            left++;
        else if(sum>B)
            right--;
        else{
            left++;
            count++;
        }
    }
    return count;
}