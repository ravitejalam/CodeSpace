#include <bits/stdc++.h>

using namespace std;

int divide(int A, int B)
{
    int sign = ((A < 0) ^ (B < 0)) ? -1 : 1;
    if (A == INT_MIN)
    {
        if (B == -1)
            return INT_MAX;
        if (B == 1)
            return A;
        A = INT_MAX;
    }
    A = abs(A);
    B = abs(B);

    int quotient = 0;
    while (A >= B)
    {
        A -= B;
        ++quotient;
    }

    return sign * quotient;
}

int main()
{
    cout << divide(-2147483648, -10000000);
    return 0;
}
