#include <bits/stdc++.h>
using namespace std;

int Solution::solve(vector<int> &A, int B)
{
    int curr_sum = 0;
    int n = A.size();
    for (int i = 0; i < B; i++)
    {
        curr_sum += A[n - 1 - i];
    }
    int max_sum = curr_sum;
    for (int i = 0; i < B; i++)
    {
        curr_sum -= A[n - B + i];
        curr_sum += A[i];
        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}
