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
long long int fact(long long int num, long long p, long long int r)
{
    long long res = 1;
    while (num > r)
    {
        res = ((res) % p * (num) % p) % p;
        num--;
    }
    return res;
}
int solve(int A, int B, int C)
{
    int total_wins_till_now = C - 1, total_matchs_till_now = A - 1;
    long long int numerator, denominator;

    if (total_matchs_till_now - total_wins_till_now > total_wins_till_now)
    {
        numerator = fact(total_matchs_till_now, M, total_matchs_till_now - total_wins_till_now);
        denominator = fact(total_wins_till_now, M, 1);
    }
    else
    {
        numerator = fact(total_matchs_till_now, M, total_wins_till_now);
        denominator = fact(total_matchs_till_now - total_wins_till_now, M, 1);
    }
    long long int res = (numerator * modInverse(denominator, M)) % M;
    res = (res * power(B - 1, A - C, M)) % M;
    res = (res * modInverse(power(B, A, M), M)) % M;
    return res;
}

int main()
{
    cout << solve(1, 2, 1);
    return 0;
}
