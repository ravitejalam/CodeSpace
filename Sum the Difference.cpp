#define M 1000000007

long long int power(int i)
{
    if(i==0)
        return 1;
    long long int sum = 1;
    for (int j = 0; j < i; j++)
    {
        sum = (sum*2)%M;
    }
    return sum;
}

int Solution::solve(vector<int> &A)
{
    sort(A.begin(), A.end());
    long long int sum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        long long int p = power(i);
        sum = (sum + p * A[i]) % M;
        p = power(A.size() - 1 - i);
        sum = (sum + M - (p * A[i])) % M;
    }
    return sum;
}