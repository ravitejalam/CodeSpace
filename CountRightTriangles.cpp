#define M 1000000007

int Solution::solve(vector<int> &A, vector<int> &B) {
    long long ans = 0;
    unordered_map<int,int> X;
    unordered_map<int,int> Y;
    for (int i = 0; i < A.size(); i++)
    {
        X[A[i]]++;
        Y[B[i]]++;
    }
    for (int i = 0; i < A.size(); i++)
    {
        ans+=((X[A[i]]-1)*(Y[B[i]]-1))%M;
    }
    return ans;
}