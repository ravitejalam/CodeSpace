#include <bits/stdc++.h>

using namespace std;

int findMinXor(vector<int> &A)
{
    sort(A.begin(), A.end());
    int MinXOR = INT_MAX;
    for (int i = 1; i < A.size(); i++)
    {
        int XOR = A[i] ^ A[i - 1];
        if (XOR < MinXOR)
        {
            MinXOR = XOR;
        }
    }
    return MinXOR;
}

int main()
{
    vector<int> A = {12, 4, 6, 2};
    cout << findMinXor(A);
    return 0;
}
