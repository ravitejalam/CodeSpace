#include <bits/stdc++.h>
#define M 1000000007

using namespace std;

long long int power(long long int x, long long int y, long long int p)
{
    long long int res = 1;
    while (y > 0)
    {
        x %= p;
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

long long int modInverse(long long int n, long long int p)
{
    return power(n, p - 2, p);
}