#include <bits/stdc++.h>

using namespace std;

vector<int> primesum(int A)
{
    vector<bool> isPrime(A + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    vector<int> ans(2);
    for (int i = 2; i * i <= A; i++)
    {
        if (isPrime[i])
        {
            for (int j = 2 * i; j <= A; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= A / 2; i++)
    {
        if (isPrime[i] && isPrime[A - i])
        {
            ans[0] = i;
            ans[1] = A - i;
            return ans;
        }
    }
}

int main()
{
    vector<int> B = primesum(1048574);
    return 0;
}
