#include <bits/stdc++.h>

using namespace std;

string solve(vector<int> &A)
{
    int count = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] & 1)
            count++;
    }
    return count % 2 == 0 ? "Yes" : "No";
}

int main()
{
    vector<int> A = {9, 17};
    cout << solve(A);
    return 0;
}
