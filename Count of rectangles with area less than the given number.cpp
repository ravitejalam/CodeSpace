#define M 1000000007

int Solution::solve(vector<int> &A, int B) {
    int left = 0;
    int right = A.size()-1;
    long int count = 0;
    while (left<A.size() && right>=0)
    {
        if(1L*A[left]*A[right]<B){
            count = (count + (right + 1)%M)%M;
            left++;
        }
        else{
            right--;
        }
    }
    return count;
}