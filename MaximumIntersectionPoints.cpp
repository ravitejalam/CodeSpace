#include <bits/stdc++.h>

using namespace std;

long long int nCr(int n, int r)
{
    if (n == 0)
        return 0;
    else if (n == 1)
    {
        if (r == 2)
            return 0;
        else
            return 1;
    }

    long long int res = 1;
    for (int i = n; i > max(r, n - r); i--)
    {
        res *= i;
    }
    for (int i = 2; i <= min(r, n - r); i++)
    {
        res /= i;
    }
    return res;
}

int getIntersection(int A, int B)
{
    int n = A > B ? A : B;
    return nCr(A, 2) + (2 * nCr(B, 2) + (2 * nCr(A, 1) * nCr(B, 1)));
}

int main()
{
    cout << getIntersection(0, 0);
    return 0;
}
