int Solution::solve(vector<int> &A) {
    vector<long long int> pre(A.size()+1);
    for (int i = 1; i < A.size()+1; i++)
    {
        pre[i] = pre[i-1] + A[i-1];
    }
    unordered_set<long long int> s = {};
    for (int i = 0; i < A.size()+1; i++)
    {
        if(s.find(pre[i]) == s.end())
            s.insert(pre[i]);
        else
            return 1;        
    }
    return 0;
}