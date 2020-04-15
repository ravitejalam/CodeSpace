#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &A, vector<int> &B)
{
    double ans = 1;
    for (int i = 0; i < A.size(); i++)
    {
        ans*=A[i];
        ans/=B[i];
    }
    if(ans>=1)
        return 1;
    return 0;
}