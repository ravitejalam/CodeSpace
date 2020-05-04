#define M 1000000007

vector<int> Solution::solve(vector<int> &A)
{
    sort(A.begin(), A.end());
    long long min_diff = 0, max_diff = 0;
    for (int i = 0; i < A.size() / 2; i++)
    {
        min_diff += (A[2 * i + 1] - A[2 * i]);
        min_diff %= M;
        max_diff += (A[A.size() - 1 - i] - A[i]);
        max_diff %= M;
    }
    vector<int> ans = {(int)max_diff,(int)min_diff};
    return ans;
}