#include <bits/stdc++.h>
#define M 1000000007
using namespace std;

int cntBits(vector<int> &A)
{
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        int set = 0;
        for (int j = 0; j < A.size(); j++)
        {
            if (A[j] & (1 << i))
                set = (set + 1);
        }
        count = (count % M + (set * (A.size()-set)) % M) % M;
    }
    return (2 * count) % M;
}

int main()
{
    vector<int> A = {1, 3, 5};
    cout << cntBits(A);
    return 0;
}
