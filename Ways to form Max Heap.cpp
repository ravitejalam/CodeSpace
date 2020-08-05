#define M 1000000007

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

int nCrModPFermat(int n, int r, int p)
{
    if (r == 0)
        return 1;

    long long int fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    long long int MI1 = (modInverse(fac[r], p) % p), MI2 = (modInverse(fac[n - r], p) % p), MI = (MI1 * MI2) % p;
    return ((fac[n] % p) * MI) % p;
}

int getMaxHeapsCount(int n)
{
    if (n <= 1)
        return 1;
    int h = log2(n);
    int m = pow(2, h);
    int p = n - (m - 1);
    int l;
    if (p > m / 2)
        l = m - 1;
    else
        l = m - 1 - m / 2 + p;
    long long int ans = nCrModPFermat(n - 1, l, M) % M;
    long long int left = getMaxHeapsCount(l) % M;
    long long int right = getMaxHeapsCount(n - 1 - l) % M;
    ans = (ans * left) % M;
    ans = (ans * right) % M;
    return ans;
}

int Solution::solve(int A)
{
    return getMaxHeapsCount(A);
}