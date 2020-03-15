#include <bits/stdc++.h>

using namespace std;

int singleNumber(const vector<int> &A)
{
    int XOR = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        XOR = XOR ^ A[i];
    }
    return XOR;
}

int main()
{
    vector<int> A = {1, 2, 2, 3, 1};
    cout << singleNumber(A);
    return 0;
}
