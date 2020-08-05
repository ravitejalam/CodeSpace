int findans(int flag[], vector<int> A)
{
    vector<int> temp;
    for (int i = 0; i < A.size(); i++)
    {
        if (flag[i] == 0)
        {
            temp.push_back(A[i]);
        }
    }
    int ans = 0;
    for (int i = 1; i < temp.size(); i += 2)
    {
        ans += temp[i] - temp[i - 1];
    }
    return ans;
}

int Solution::solve(vector<int> &A)
{
    int n = A.size() / 2;
    int flag[A.size()];
    memset(flag, 0, sizeof(flag));
    int ans = INT_MAX;
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i + 1; j < A.size(); j++)
        {
            flag[i] = 1;
            flag[j] = 1;
            ans = min(ans, findans(flag, A));
            flag[i] = 0;
            flag[j] = 0;
        }
    }
    return ans;
}