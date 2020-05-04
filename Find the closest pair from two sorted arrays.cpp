vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C)
{
    int n = A.size();
    int m = B.size();

    int i = 0, j = m - 1;
    vector<int> v;
    int maxx = INT_MAX;
    int res_l, res_r;
    while (i < n && j >= 0)
    {
        if (abs(A[i] + B[j] - C) < maxx)
        {
            res_l = i;
            res_r = j;
            maxx = abs(A[i] + B[j] - C);
        }
        else if (abs(A[i] + B[j] - C) == maxx && res_l == i)
        {
            res_r = j;
        }
        if (A[i] + B[j] > C)
            j--;
        else
            i++;
    }
    v.push_back(A[res_l]);
    v.push_back(B[res_r]);
    return v;
}