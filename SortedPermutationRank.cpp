
#include <bits/stdc++.h>

using namespace std;

long factorial(int n)
{
    if (n > 1)
        return (n % 1000003 * factorial(n - 1) % 1000003) % 1000003;
    else
        return 1;
}

int findRank(string A)
{
    int rank = 1, s = A.size();
    for (int i = 0; i < s; i++)
    {
        int count = 0;
        for (int j = i + 1; j < s; j++)
        {
            A[i] > A[j] ? count++ : true;
        }
        rank += ((count % 1000003) * (factorial(s - i - 1) % 1000003)) % 1000003;
    }
    return rank % 1000003;
}

int main()
{
    cout << findRank("acb");
    return 0;
}
