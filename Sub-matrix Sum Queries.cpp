int getSum(vector<vector<long long int>> &preSum, int x1, int y1, int x2, int y2)
{
    int M = 1000000007;
    long long int ans = preSum[x2][y2] + preSum[x1 - 1][y1 - 1] - preSum[x1 - 1][y2] - preSum[x2][y1 - 1];
    while (ans < 0)
    {
        ans += M;
    }
    return ans % M;
}

vector<int> Solution::solve(vector<vector<int>> &A, vector<int> &B, vector<int> &C, vector<int> &D, vector<int> &E)
{
    vector<vector<long long int>> preSum(A.size() + 1, vector<long long int>(A[0].size() + 1, 0));
    int M = 1000000007;
    for (int row = 1; row < A.size() + 1; row++)
    {
        for (int col = 1; col < A[0].size() + 1; col++)
        {
            preSum[row][col] = preSum[row - 1][col] - preSum[row - 1][col - 1] + A[row - 1][col - 1] + preSum[row][col - 1];
            // while(preSum[row][col]<0){
            //     preSum[row][col] += M;
            // }
        }
    }
    vector<int> ans = {};
    for (int q = 0; q < B.size(); q++)
    {
        ans.push_back(getSum(preSum, B[q], C[q], D[q], E[q]));
    }
    return ans;
}