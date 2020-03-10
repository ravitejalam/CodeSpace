#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A)
{
    int c = 0;
    int i = 0;
    while (i < A.size() - 1)
    {
        if(A[i]==0){
            return -1;
        }
        if (A[i] + i >= A.size() - 1)
        {
            c++;
            break;
        }
        int max_jump = INT_MIN, max_index;
        for (int j = 1; j <= A[i]; j++)
        {
            if (A[i + j] + j > max_jump)
            {
                max_jump = A[i + j] + j;
                max_index = j;
            }
        }
        i+=max_index;
        c++;
    }
    return c;
}

int main()
{
    vector<int> A = {5, 17, 100, 11};
    cout << solve(A);
    return 0;
}
